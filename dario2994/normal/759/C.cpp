#ifndef SEGMENT_TREE
#define SEGMENT_TREE

// Segment tree data structure implementation
//
// All the queries have complexity log(N)
//
// Value is the value stored in each element.
// The constructor must receive as parameter, both null_value which is the value
// that is the identity for the operation (e.g. 0 for +, 1 for *) and
// join_values which is a function that compute the value of the father given
// the values of the child (e.g. for the sum the lambda
// [](const int& a, const int& b){return a+b} is sufficient).
//
// Operation is the Operation that we can apply on the array.
// It's a class that must implement the following methods (it is not a C++
// concept to keep compatibility with older compilers):
//  void Append(const Operation& other, int size):
//      New operation to be applied after the current one. 
//  Operation Left(int size) const
//      The operation to be transmitted to the left child.
//  Operation Right(int size) const
//      The operation to be transmitted to the right child.
//  void Apply(Value& val, int size) const
//      Apply the operation to val.
//  Operation Specialize(int a, int b, int l, int r) const
//      Specialize the operation for the interval [a, b) given that initially
//      the operation was on the interval [l, r). You can assume that the interval
//      [a, b) is contained in the interval [l, r).
//      n.b. For simple queries this will probably be the identity.
//  bool empty() const
//      Is this operation empty?
//  void Clear()
//      Make this operation empty.
//  The size passed by parameter is the size of the current vertex (it might
//  be needed to perform some operations).

#include <vector>
#include <functional>
#include <iostream>
using namespace std;

// All ranges are [a, b)
template <typename Value, class Operation>
class SegmentTree {
    typedef function<Value(const Value&, const Value&)> ValueJoiner;
    
  public:
    Value GetRange(int l, int r) {
        return _GetRange(1, 0, leaves_number, l, r); 
    }
    Value GetValue(int index) {
        return _GetRange(1, 0, leaves_number, index, index+1);
    }
    
    void ApplyRangeOperation(int l, int r, const Operation& op) {
        _ApplyRangeOperation(1, 0, leaves_number, l, r, op);
    }
    void ApplyOperation(int index, const Operation& op) {
        _ApplyRangeOperation(1, 0, leaves_number, index, index+1, op);
    }

    // Returns the index of the first leaf such that condition is true in the
    // value of the leaf.
    // If no such leaf exists, return -1.
    // The condition must be such that it holds for a node iff it holds
    // for at least one of the children.
    int BinarySearch(const std::function<bool(Value)>& condition) {
        if (!condition(tree[1].value)) {
            return -1;
        }
        return _BinarySearch(1, leaves_number, condition);
    }
    
    SegmentTree(int size,
                ValueJoiner join_values, Value null_value) :
            join_values(join_values),
            null_value(null_value) {
        leaves_number = 1;
        while (leaves_number < size) leaves_number *= 2;
        tree = vector<Vertex>(2*leaves_number, null_value);
    }
    
    SegmentTree(const vector<Value>& initial_values,
                ValueJoiner join_values, Value null_value) :
            join_values(join_values),
            null_value(null_value) {
        leaves_number = 1;
        while (leaves_number < (int)initial_values.size()) {
            leaves_number *= 2;
        }
        tree = vector<Vertex>(2*leaves_number, null_value);
        for (int i = 0; i < (int)initial_values.size(); i++) {
            tree[leaves_number+i].value = initial_values[i];
        }
        for (int i = leaves_number-1; i > 0; i--) {
            tree[i].value = join_values(tree[2*i].value, tree[2*i+1].value);
        }
    }

    void Debug(function<string(Value)> ValueToString) {
        cout << endl;
        for (int v = 1; v < (int)tree.size(); v++) {
            cout << v << ": " << tree[v].ToString(ValueToString) << endl;
        }
        cout << endl;
    }
    
  private:
    struct Vertex {
        Value value;
        Operation operation;

        Vertex(Value value) :
                value(value){
            operation.Clear();
        }
        
        inline bool no_op() {
            return operation.empty();
        }
        inline void NewOperation(const Operation& op, int size) {
            operation.Append(op, size);
            op.Apply(value, size);
        }
        inline void DeleteOperation() {
            operation.Clear();
        }

        string ToString(function<string(Value)> ValueToString) {
            string res = "(value: ";
            res += ValueToString(value);
            res += ", operation: ";
            res += operation.ToString();
            res += ")";
            return res;
        }
    };
    // The tree containing the data structure.
    // The root of the tree is the vertex indexed by 1.
    // The left child of a vertex with index v is 2*v, the right child is 2*v+1.
    vector <Vertex> tree; 
    // Number of leaves of the tree. Should be tree.size()/2.
    int leaves_number;
    // How to calculate the value of the father, given the values of the
    // children.
    ValueJoiner join_values;
    const Value null_value;
    
    void DelegateOperation(int v, int size) {
        if (tree[v].no_op()) return;
        tree[2*v].NewOperation(tree[v].operation.Left(size), size/2);
        tree[2*v+1].NewOperation(tree[v].operation.Right(size), size/2);
        tree[v].DeleteOperation();
    }
    
    void _ApplyRangeOperation(int v, int a, int b, const int l, const int r,
                              const Operation& op) {
        if (b <= l or r <= a) return; 
        if (l <= a and b <= r) {
            const Operation& spec_op = op.Specialize(a, b, l, r);
            tree[v].NewOperation(spec_op, b-a);
            return;
        }
        DelegateOperation(v, b-a);
        int m = (a+b)/2;
        _ApplyRangeOperation(2*v,   a, m, l, r, op);
        _ApplyRangeOperation(2*v+1, m, b, l, r, op);
        tree[v].value = join_values(tree[2*v].value, tree[2*v+1].value);
    }
    
    Value _GetRange(int v, int a, int b, const int l, const int r) {
        if (b <= l or r <= a) return null_value;
        if (l <= a and b <= r) return tree[v].value;
        DelegateOperation(v, b-a);
        int m = (a+b)/2;
        return join_values(_GetRange(2*v,   a, m, l, r), 
                           _GetRange(2*v+1, m, b, l, r));
    }

    int _BinarySearch(int v, int size,
                      const std::function<bool(Value)>& condition) {
        if (v >= leaves_number) return v - leaves_number;
        DelegateOperation(v, size);
        if (condition(tree[2*v].value)) {
            return _BinarySearch(2*v, size/2, condition);
        }
        else {
            return _BinarySearch(2*v+1, size/2, condition);
        }
    }
};

#endif  // SEGMENT_TREE


#include <bits/stdc++.h>
// #include "../../CompetitiveProgrammingAlgos/segment_tree.cpp"
using namespace std;

const int MAXN = 100001;
int val[MAXN];

struct SumOperation {
    SumOperation() {}
    SumOperation(int y) : x(y) {}
    void Append(const SumOperation& other, int size) {
        x += other.x;
    }
    SumOperation Left(int size) const {
        return *this;
    }
    SumOperation Right(int size) const {
        return *this;
    }
    void Apply(int& val, int size) const {
        val += x;
    }
    SumOperation Specialize(int a, int b, int l, int r) const {
        return *this;
    }
    bool empty() const {
        return x == 0;
    }
    void Clear() {
        x = 0;
    }
    private:
    int x;
};

int main() {
    // ifstream in("in.txt");
    // ofstream out("out.txt");
    int N;
    cin >> N;
    SegmentTree<int, SumOperation> tree(N, [](const int& x, const int& y) { return max(x, y); }, 0);
    for (int i = 0; i < N; i++) {
        int index, t;
        cin >> index >> t;
        index = N-index;
        if (t == 1) {
            cin >> val[index];
        }
        tree.ApplyRangeOperation(index, 100000, 2*t-1);
        int first_good_index = tree.BinarySearch([](int x) { return x > 0; });
        if (first_good_index == -1) cout << -1 << "\n";
        else cout << val[first_good_index] << "\n";
    }
}