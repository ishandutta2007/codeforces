#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
    bool done_something = false;
    stringstream res;
    res << "[";
    for (; begin_iter != end_iter and counter; ++begin_iter) {
        done_something = true;
        counter--;
        res << *begin_iter << ", ";
    }
    string str = res.str();
    if (done_something) {
        str.pop_back();
        str.pop_back();
    }
    str += "]";
    return str;
}

vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
    vector<int> ord(size);
    for (int i = 0; i < size; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), compare);
    return ord;
}

template <typename T>
bool MinPlace(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool MaxPlace(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        out << v[i];
        if (i != (int)v.size()-1) out << ", ";
    }
    out << "]";
    return out;
}

#define INF 1<<30
#define eps 1e-9

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x)
    #define dbg_array(x, len)
#endif

#include <cstdint>
#include <utility>
namespace segment_tree {
typedef int int64;
struct Interval {
    Interval(int64 l, int64 r) : l(l), r(r) {}
    int64 size() const { return r-l; }
    int64 l, r;
};
bool DisjointIntervals(const Interval& int1,
                       const Interval& int2);
bool ContainedInterval(const Interval& int1,
                       const Interval& int2);
void Left(Interval& interval);
void Right(Interval& interval);
void LeftHalf(Interval& interval);
void RightHalf(Interval& interval);
void LeftDouble(Interval& interval);
void RightDouble(Interval& interval);
}
namespace segment_tree {
bool DisjointIntervals(const Interval& int1,
                       const Interval& int2) {
    return int1.r <= int2.l or int2.r <= int1.l;
}
bool ContainedInterval(const Interval& int1,
                       const Interval& int2) {
    return int2.l <= int1.l and int1.r <= int2.r;
}
void Left(Interval& interval) {
    interval.r = 2*interval.l - interval.r;
    std::swap(interval.l, interval.r);
}
void Right(Interval& interval) {
    interval.l = 2*interval.r-interval.l;
    std::swap(interval.l, interval.r);
}
void LeftHalf(Interval& interval) {
    interval.r = interval.l + ((interval.r-interval.l)>>1);
}
void RightHalf(Interval& interval) {
    interval.l = interval.l + ((interval.r-interval.l)>>1);
}
void LeftDouble(Interval& interval) {
    interval.l = 2*interval.l-interval.r;
}
void RightDouble(Interval& interval) {
    interval.r = 2*interval.r-interval.l;
}
}
#include <vector>
namespace segment_tree {
template <typename T>
class ContiguousBinaryTree {
  public:
    explicit ContiguousBinaryTree(int64 size) : size(size), container(size*2) {}
    class iterator {
      public:
        explicit iterator(ContiguousBinaryTree* tree);
        iterator(ContiguousBinaryTree* tree, int64 leaf_index);
        void GoToFather();
        void GoLeft();
        void GoRight();
        iterator FatherNode() const;
        iterator LeftChild() const;
        iterator RightChild() const;
        T& operator *() { return tree->container[v]; }
        T* operator ->() { return &(tree->container[v]); }
        bool IsRoot() const { return v == 1; }
        bool IsLeaf() const { return v >= tree->size; }
        int64 GetIndex() { return v; }
        int64 LeafIndex() const { return v - tree->size; }
        int64 LeftIndex() const { return interval.l; }
        int64 RightIndex() const { return interval.r; }
        Interval GetInterval() const { return interval; }
        void operator --(int);
        void operator ++(int);
        bool IsEnd() { return interval.size() == 0; }
      private:
        ContiguousBinaryTree<T>* tree;
        int64 v;
        Interval interval;
    };
    iterator GetRoot() { return iterator(this); }
    iterator GetLeaf(int64 index) { return iterator(this, index); }
    typedef iterator debug_iterator;
    debug_iterator GetDebugIterator() { return debug_iterator(this); }
  private:
    const int64 size;
    std::vector<T> container;
};
}
namespace segment_tree {
template <typename T>
ContiguousBinaryTree<T>::iterator::iterator(ContiguousBinaryTree<T>* tree) :
        tree(tree), v(1), interval(0, tree->size) {}
template <typename T>
ContiguousBinaryTree<T>::iterator::iterator(ContiguousBinaryTree<T>* tree,
                                            int64 leaf_index) :
        tree(tree),
        v(tree->size + leaf_index),
        interval(leaf_index, leaf_index+1) {}
template <typename T>
void ContiguousBinaryTree<T>::iterator::GoToFather() {
    if (v&1) {
        LeftDouble(interval);
    } else {
        RightDouble(interval);
    }
    v >>= 1;
}
template <typename T>
void ContiguousBinaryTree<T>::iterator::GoLeft() {
    v <<= 1;
    LeftHalf(interval);
}
template <typename T>
void ContiguousBinaryTree<T>::iterator::GoRight() {
    v = (v<<1)|1;
    RightHalf(interval);
}
template <typename T>
typename ContiguousBinaryTree<T>::iterator
        ContiguousBinaryTree<T>::iterator::FatherNode() const {
    auto other = *this;
    other.GoToFather();
    return other;
}
template <typename T>
typename ContiguousBinaryTree<T>::iterator
        ContiguousBinaryTree<T>::iterator::LeftChild() const {
    iterator other = *this;
    other.GoLeft();
    return other;
}
template <typename T>
typename ContiguousBinaryTree<T>::iterator
        ContiguousBinaryTree<T>::iterator::RightChild() const {
    iterator other = *this;
    other.GoRight();
    return other;
}
template <typename T>
void ContiguousBinaryTree<T>::iterator::operator --(int) {
    v--;
    if (v & (v+1)) {
        Right(interval);
    } else {
        int64 sz = interval.size();
        interval.r = tree->size;
        interval.l = interval.r - (sz << 1);
    }
}
template <typename T>
void ContiguousBinaryTree<T>::iterator::operator ++(int) {
    v++;
    if (v & (v-1)) {
        Left(interval);
    } else {
        int sz = interval.size();
        interval.l = 0;
        interval.r = sz >> 1;
    }
}
}
#include <memory>
namespace segment_tree {
template <typename T>
class SparseBinaryTree {
    struct Vertex {
        enum ChildSide {
            LeftChild,
            RightChild
        };
        Vertex() : father(nullptr) {}
        Vertex(Vertex* father, ChildSide child_side) :
                father(father), child_side(child_side) {}
        Vertex* father;
        std::unique_ptr<Vertex> left_child;
        std::unique_ptr<Vertex> right_child;
        ChildSide child_side;
        T val;
    };
  public:
    SparseBinaryTree(int64 size) : size(size) {}
    class iterator {
      public:
        explicit iterator(SparseBinaryTree* tree) :
                vertex(&(tree->root)), interval(0, tree->size) {}
        void GoToFather();
        void GoLeft();
        void GoRight();
        iterator FatherNode() const;
        iterator LeftChild() const;
        iterator RightChild() const;
        T& operator *() { return vertex->val; }
        T* operator ->() { return &(vertex->val); }
        bool IsRoot() const { return vertex->father == nullptr; }
        bool IsLeaf() const { return interval.l + 1 == interval.r; }
        int64 LeafIndex() const { return interval.l; }
        int64 LeftIndex() const { return interval.l; }
        int64 RightIndex() const { return interval.r; }
        Interval GetInterval() const { return interval; }
      private:
        Vertex* vertex;
        Interval interval;
    };
    class debug_iterator {
      public:
        debug_iterator(SparseBinaryTree* tree) : vertex(&(tree->root)), v(1) {}
        void operator ++(int);
        T& operator *() { return vertex->val; }
        const T& operator *() const { return vertex->val; }
        T* operator ->() { return &(vertex->val); }
        const T* operator ->() const { return &(vertex->val); }
        bool IsEnd() { return v == 0; }
        int64 GetIndex() { return v; }
      private:
        Vertex* vertex;
        int64 v;
    };
    iterator GetRoot() { return iterator(this); }
    debug_iterator GetDebugIterator() { return debug_iterator(this); }
  private:
    const int64 size;
    Vertex root;
};
}
namespace segment_tree {
template <typename T>
void SparseBinaryTree<T>::iterator::GoToFather() {
    typedef SparseBinaryTree<T>::Vertex Vertex;
    if (vertex->child_side == Vertex::RightChild) {
        LeftDouble(interval);
    } else {
        RightDouble(interval);
    }
    vertex = vertex->father();
}
template <typename T>
void SparseBinaryTree<T>::iterator::GoLeft() {
    typedef SparseBinaryTree<T>::Vertex Vertex;
    if (vertex->left_child == nullptr) {
        vertex->left_child =
                std::make_unique<Vertex>(vertex, Vertex::LeftChild);
    }
    vertex = vertex->left_child.get();
    LeftHalf(interval);
}
template <typename T>
void SparseBinaryTree<T>::iterator::GoRight() {
    typedef SparseBinaryTree<T>::Vertex Vertex;
    if (vertex->right_child == nullptr) {
        vertex->right_child =
                std::make_unique<Vertex>(vertex, Vertex::RightChild);
    }
    vertex = vertex->right_child.get();
    RightHalf(interval);
}
template <typename T>
typename SparseBinaryTree<T>::iterator
        SparseBinaryTree<T>::iterator::FatherNode() const {
    auto other = *this;
    other.GoToFather();
    return other;
}
template <typename T>
typename SparseBinaryTree<T>::iterator
        SparseBinaryTree<T>::iterator::LeftChild() const {
    auto other = *this;
    other.GoLeft();
    return other;
}
template <typename T>
typename SparseBinaryTree<T>::iterator
        SparseBinaryTree<T>::iterator::RightChild() const {
    auto other = *this;
    other.GoRight();
    return other;
}
template <typename T>
void SparseBinaryTree<T>::debug_iterator::operator ++(int) {
    typedef SparseBinaryTree<T>::Vertex Vertex;
    if (vertex->left_child != nullptr) {
        v <<= 1;
        vertex = vertex->left_child.get();
    } else if (vertex->right_child != nullptr){
        v = (v<<1)+1;
        vertex = vertex->right_child.get();
    } else {
        while (v != 1 &&
               (vertex->child_side == Vertex::RightChild ||
                vertex->father->right_child == nullptr)) {
            v >>= 1;
            vertex = vertex->father;
        }
        if (v == 1) {
            v = 0;
            vertex = nullptr;
        } else {
            v += 1;
            vertex = vertex->father->right_child.get();
        }
    }
}
}
#include <iostream>
#include <functional>
#include <vector>
namespace segment_tree {
template <typename Value, typename Operation>
class SegmentTreeBase {
  public:
    virtual Value GetRange(int64 l, int64 r) const = 0;
    virtual Value GetValue(int64 index) const = 0;
    virtual void ApplyRangeOperation(int64 l, int64 r, const Operation& op) = 0;
    virtual void ApplyOperation(int64 index, const Operation& op) = 0;
    virtual int64 LastBefore(int64 index,
            const std::function<bool(const Value&)>& condition) const = 0;
    virtual int64 FirstAfter(int64 index,
            const std::function<bool(const Value&)>& condition) const = 0;
    virtual void Debug(
            std::function<std::string(const Value&)> ValueToString) const = 0;
};
template <typename Value, typename Operation,
          template <typename ___> class BinaryTree>
class SegmentTree : public SegmentTreeBase<Value, Operation> {
    typedef std::function<Value(const Value&, const Value&)> ValueJoiner;
    struct Vertex {
        Vertex() : contains_pending_operation(false) {}
        bool no_op() const { return !contains_pending_operation; }
        const Operation& GetOperation() const { return operation; }
        void NewOperation(const Operation& op, int64 size);
        void DeleteOperation() { contains_pending_operation = false; }
        std::string ToString(
                std::function<std::string(Value)> ValueToString) const;
        Value value;
      private:
        bool contains_pending_operation;
        Operation operation;
    };
    typedef typename BinaryTree<Vertex>::iterator TreeIterator;
  public:
    SegmentTree(int64 size, ValueJoiner join_values);
    SegmentTree(int64 size, const Value& initial_value, ValueJoiner join_values);
    SegmentTree(const std::vector<Value>& initial_values,
                ValueJoiner join_values);
    Value GetRange(int64 l, int64 r) const;
    Value GetValue(int64 index) const;
    void ApplyRangeOperation(int64 l, int64 r, const Operation& op);
    void ApplyOperation(int64 index, const Operation& op);
    int64 LastBefore(int64 index,
            const std::function<bool(const Value&)>& condition) const;
    int64 FirstAfter(int64 index,
            const std::function<bool(const Value&)>& condition) const;
    void Debug(std::function<std::string(const Value&)> ValueToString) const;
  private:
    void DelegateOperation(TreeIterator it) const;
    void _ApplyRangeOperation(TreeIterator it, const Interval& interval,
                              const Operation& op);
    Value _GetRange(TreeIterator it, const Interval& interval) const;
    int64 _LastBefore(TreeIterator it, int64 index,
            const std::function<bool(const Value&)>& condition) const;
    int64 _FirstAfter(TreeIterator it, int64 index,
            const std::function<bool(const Value&)>& condition) const;
    const int64 size; 
    ValueJoiner join_values;
    const int64 leaves_number;
    mutable BinaryTree<Vertex> tree; 
};
}
namespace segment_tree {
#define TEMPLATES_DECLARATION \
template <typename Value, typename Operation, \
          template <typename ___> class BinaryTree>
#define TEMPLATE_NAMES Value, Operation, BinaryTree
TEMPLATES_DECLARATION
void SegmentTree<TEMPLATE_NAMES>::Vertex::NewOperation(
        const Operation& op, int64 size) {
    if (!contains_pending_operation) {
        contains_pending_operation = true;
        operation = op;
    } else {
        operation.Append(op, size);
    }
    op.Apply(value, size);
}
TEMPLATES_DECLARATION
std::string SegmentTree<TEMPLATE_NAMES>::Vertex::ToString(
        std::function<std::string(Value)> ValueToString) const {
    std::string res = "(value: {";
    res += ValueToString(value);
    res += "}, ";
    if (contains_pending_operation) {
        res += "operation: ";
        res += operation.ToString();
    } else {
        res += "no_op";
    }
    res += ")";
    return res;
}
namespace {
int64 ComputeLeavesNumber(int64 size) {
    int64 leaves_number = 1;
    while (leaves_number < size) leaves_number <<= 1;
    return leaves_number;
}
}
TEMPLATES_DECLARATION
SegmentTree<TEMPLATE_NAMES>::SegmentTree(int64 size, ValueJoiner join_values) :
        size(size),
        join_values(join_values),
        leaves_number(ComputeLeavesNumber(size)),
        tree(leaves_number) {}
TEMPLATES_DECLARATION
SegmentTree<TEMPLATE_NAMES>::SegmentTree(int64 size,
        const Value& initial_value, ValueJoiner join_values) :
        SegmentTree(size, join_values) {
    auto leaf_it = tree.GetLeaf(0);
    leaf_it--;
    for (int64 i = 0; i < size; i++) {
        leaf_it++;
        leaf_it->value = initial_value;
    }
    auto node_it = tree.GetLeaf(0);
    while (!node_it.IsRoot()) {
        node_it--;
        node_it->value = join_values(node_it.LeftChild()->value,
                                     node_it.RightChild()->value);
    }
}
TEMPLATES_DECLARATION
SegmentTree<TEMPLATE_NAMES>::SegmentTree(
        const std::vector<Value>& initial_values, ValueJoiner join_values) :
        SegmentTree(initial_values.size(), join_values) {
    auto leaf_it = tree.GetLeaf(0);
    leaf_it--;
    for (const Value& val : initial_values) {
        leaf_it++;
        leaf_it->value = val;
    }
    auto node_it = tree.GetLeaf(0);
    while (!node_it.IsRoot()) {
        node_it--;
        node_it->value = join_values(node_it.LeftChild()->value,
                                     node_it.RightChild()->value);
    }
}
TEMPLATES_DECLARATION
Value SegmentTree<TEMPLATE_NAMES>::GetRange(int64 l, int64 r) const {
    return _GetRange(tree.GetRoot(), Interval(l, r)); 
}
TEMPLATES_DECLARATION
Value SegmentTree<TEMPLATE_NAMES>::GetValue(int64 index) const {
    return _GetRange(tree.GetRoot(), Interval(index, index+1));
}
TEMPLATES_DECLARATION
void SegmentTree<TEMPLATE_NAMES>::ApplyRangeOperation(
        int64 l, int64 r, const Operation& op) {
    _ApplyRangeOperation(tree.GetRoot(), Interval(l, r), op);
}
TEMPLATES_DECLARATION
void SegmentTree<TEMPLATE_NAMES>::ApplyOperation(
        int64 index, const Operation& op) {
    _ApplyRangeOperation(tree.GetRoot(), Interval(index, index+1), op);
}
TEMPLATES_DECLARATION
int64 SegmentTree<TEMPLATE_NAMES>::LastBefore(int64 index,
        const std::function<bool(const Value&)>& condition) const {
    return _LastBefore(tree.GetRoot(), index, condition);
}
TEMPLATES_DECLARATION
int64 SegmentTree<TEMPLATE_NAMES>::FirstAfter(int64 index,
        const std::function<bool(const Value&)>& condition) const {
    int64 res = _FirstAfter(tree.GetRoot(), index, condition);
    return (res < size) ? res : -1;
}
TEMPLATES_DECLARATION
void SegmentTree<TEMPLATE_NAMES>::Debug(
        std::function<std::string(const Value&)> ValueToString) const {
    std::cout << std::endl;
    for (auto it = tree.GetDebugIterator(); !it.IsEnd(); it++) {
        std::cout << it.GetIndex() << ": " << it->ToString(ValueToString)
                  << std::endl;
    }
    std::cout << std::endl;
}
TEMPLATES_DECLARATION
void SegmentTree<TEMPLATE_NAMES>::DelegateOperation(TreeIterator it) const {
    if (it->no_op()) return;
    int64 l = it.LeftIndex();
    int64 r = it.RightIndex();
    int64 m = (l + r) >> 1;
    int64 half_size = (r - l) >> 1;
    it.LeftChild()->NewOperation(it->GetOperation().Restrict(l, m, l, r),
                                 half_size);
    it.RightChild()->NewOperation(it->GetOperation().Restrict(m, r, l, r),
                                  half_size);
    it->DeleteOperation();
}
TEMPLATES_DECLARATION
void SegmentTree<TEMPLATE_NAMES>::_ApplyRangeOperation(
        TreeIterator it, const Interval& interval, const Operation& op) {
    if (DisjointIntervals(it.GetInterval(), interval)) return; 
    if (ContainedInterval(it.GetInterval(), interval)) {
        const Operation& restricted_op =
                op.Restrict(it.LeftIndex(), it.RightIndex(),
                            interval.l, interval.r);
        it->NewOperation(restricted_op, it.GetInterval().size());
        return;
    }
    DelegateOperation(it);
    _ApplyRangeOperation(it.LeftChild(), interval, op);
    _ApplyRangeOperation(it.RightChild(), interval, op);
    it->value = join_values(it.LeftChild()->value, it.RightChild()->value);
}
TEMPLATES_DECLARATION
Value SegmentTree<TEMPLATE_NAMES>::_GetRange(TreeIterator it,
                                             const Interval& interval) const {
    if (ContainedInterval(it.GetInterval(), interval)) return it->value;
    DelegateOperation(it);
    if (DisjointIntervals(it.LeftChild().GetInterval(), interval)) {
        return _GetRange(it.RightChild(), interval);
    }
    if (DisjointIntervals(it.RightChild().GetInterval(), interval)) {
        return _GetRange(it.LeftChild(), interval);
    }
    return join_values(_GetRange(it.LeftChild(), interval), 
                       _GetRange(it.RightChild(), interval));
}
TEMPLATES_DECLARATION
int64 SegmentTree<TEMPLATE_NAMES>::_LastBefore(TreeIterator it, int64 index,
        const std::function<bool(const Value&)>& condition) const {
    if (it.IsLeaf()) {
        return condition(it->value) ? it.LeafIndex() : -1;
    }
    if (it.RightIndex() <= index && !condition(it->value)) {
        return -1;
    }
    DelegateOperation(it);
    auto right_child = it.RightChild();
    if (right_child.LeftIndex() < index) {
        int64 right_res = _LastBefore(right_child, index, condition);
        if (right_res != -1) return right_res;
    }
    return _LastBefore(it.LeftChild(), index, condition);
}
TEMPLATES_DECLARATION
int64 SegmentTree<TEMPLATE_NAMES>::_FirstAfter(TreeIterator it, int64 index,
        const std::function<bool(const Value&)>& condition) const {
    if (it.IsLeaf()) {
        return condition(it->value) ? it.LeafIndex() : -1;
    }
    if (index <= it.LeftIndex() && !condition(it->value)) {
        return -1;
    }
    DelegateOperation(it);
    auto left_child = it.LeftChild();
    if (index < left_child.RightIndex()) {
        int64 left_res = _FirstAfter(left_child, index, condition);
        if (left_res != -1) return left_res;
    }
    return _FirstAfter(it.RightChild(), index, condition);
}
}
using namespace segment_tree;



///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////


struct Sum {
    Sum() {}
    Sum(int a) : x(a) {}
    void Append(const Sum& other, int64 size) {
        x += other.x;
    }
    void Apply(int& val, int64 size) const {
        val += x;
    }
    Sum Restrict(int64 a, int64 b, int64 l, int64 r) const {
        // Restrict the operation to the sub-interval [a, b) given that
        // the operation is currently on the interval [l, r).
        // You can assume that [a, b) is contained in [l, r).
        return *this;
    }

    string ToString() const { return ""; };
    private:
    int x;
};

// This should not compile if used.
const int MAXN = 36000;
const int MAXK = 60;

int st[MAXN*4];
int op[MAXN*4];
int pot;

void PushDown(int v) {
    if (op[v] == 0) return;
    if (v < pot) {
        op[2*v] += op[v];
        st[2*v] += op[v];
        op[2*v+1] += op[v];
        st[2*v+1] += op[v];
    }
    op[v] = 0;
}

void ApplyRangeOperation(int v, int l, int r, int a, int b, int x) {
    PushDown(v);
    if (r < a or b < l) return;
    if (a <= l and r <= b) {
        op[v] += x;
        st[v] += x;
        return;
    }
    int m = (l+r)/2;
    ApplyRangeOperation(2*v, l, m, a, b, x);
    ApplyRangeOperation(2*v+1, m+1, r, a, b, x);
    st[v] = max(st[2*v], st[2*v+1]);
}

int N, K;
int a[MAXN];
int ans[MAXK][MAXN];
int last_seen[MAXN];
int nn[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in online problems!

    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) last_seen[i] = N;
    for (int i = N-1; i >= 0; i--) {
        nn[i] = last_seen[a[i]];
        last_seen[a[i]] = i;
    }
    for (int i = N-1; i >= 0; i--) {
        ans[1][i] = ans[1][i+1];
        if (nn[i] == N) ans[1][i]++;
    }

    pot = 1;
    while (pot < N) pot *= 2;
    for (int t = 2; t <= K; t++) {
        for (int i = 1; i < 2*pot; i++) st[i] = op[i] = 0;
        // SegmentTree<int, Sum, ContiguousBinaryTree>
            // seg_tree(N, 0, [](int x, int y) { return max(x, y); } );
        for (int i = N-1; i >= 0; i--) {
            if (i + 1 < N) ApplyRangeOperation(1, 0, pot-1, i, i, ans[t-1][i+1]);
            ApplyRangeOperation(1, 0, pot-1, i, nn[i]-1, 1);
            ans[t][i] = st[1] + op[1];
            // if (i + 1 < N) seg_tree.ApplyOperation(i, Sum(ans[t-1][i+1]));
            // seg_tree.ApplyRangeOperation(i, nn[i], Sum(1));
            // ans[t][i] = seg_tree.GetRange(0, N);
        }
    }

    cout << ans[K][0] << "\n";
}