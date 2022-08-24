#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
using namespace std;
struct Vertex{int left; int right; int prior; int counts; int value; int pl;};
int n, xi, yi;
vector<Vertex> decart;
void push(int vertex){
    if (vertex == -1) return;
    if (decart[vertex].pl == 0) return;
    decart[vertex].value += decart[vertex].pl;
    if (decart[vertex].left != -1){
        decart[decart[vertex].left].pl += decart[vertex].pl;
    }
    if (decart[vertex].right != -1){
        decart[decart[vertex].right].pl += decart[vertex].pl;
    }
    decart[vertex].pl = 0;
}
void update(int vertex){
    if (vertex == -1){
        return;
    }
    int c = 1;
    if (decart[vertex].left != -1){
        c += decart[decart[vertex].left].counts;
    }
    if (decart[vertex].right != -1){
        c += decart[decart[vertex].right].counts;
    }
    decart[vertex].counts = c;
}
pair<int, int> split(int f, int k){
    if (f == -1){
        pair<int, int> p;
        p.first = -1;
        p.second = -1;
        return p;
    }
    push(f);
    update(f);
    int l;
    if (decart[f].left == -1) l = 0;
    else l = decart[decart[f].left].counts;
    if (l >= k){
        pair<int, int> p = split(decart[f].left, k);
        decart[f].left = p.second;
        update(f);
        p.second = f;
        return p;
    }
    pair<int, int> p = split(decart[f].right, k - l - 1);
    decart[f].right = p.first;
    p.first = f;
    update(f);
    return p;
}
int merges(int first, int second){
    push(first);
    push(second);
    update(first);
    update(second);
    if (first == -1){
        return second;
    }
    if (second == -1){
        return first;
    }
    if (decart[first].prior > decart[second].prior){
        decart[first].right = merges(decart[first].right, second);
        update(first);
        update(second);
        return first;
    }
    decart[second].left = merges(first, decart[second].left);
    update(first);
    update(second);
    return second;
}
int get_left(int vertex, int vv){
    push(vertex);
    update(vertex);
    if (vertex == -1) return 0;
    if (decart[vertex].value >= vv) return get_left(decart[vertex].left, vv);
    int ll = 1;
    if (decart[vertex].left != -1){
        ll += decart[decart[vertex].left].counts;
    }
    return get_left(decart[vertex].right, vv) + ll;
}
int right_element(int vertex){
    if (vertex == -1) return 0;
    push(vertex);
    update(vertex);
    if (decart[vertex].right == -1) return decart[vertex].value;
    return right_element(decart[vertex].right);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    int base = -1;
    int counter = 0;
    for (int i=0;i<n;i++){
        cin >> xi >> yi;
        int lind = get_left(base, xi);
        int rind = get_left(base, yi);
        if (lind < counter){
            pair<int, int> p1 = split(base, lind);
            Vertex v;
            v.left = -1;
            v.counts = 1;
            v.pl = 0;
            v.prior = rand();
            v.value = xi;
            v.right = -1;
            decart.push_back(v);
            pair<int, int> p3 = split(p1.second, rind - lind);
            if (p3.first != -1) decart[p3.first].pl ++;
            int b2 = merges(decart.size() - 1, p3.first);
            if (rind < counter) {pair<int, int> p4 = split(p3.second, 1);
            b2 = merges(p1.first, b2);
            base = merges(b2, p4.second);
            }
            else{
                counter ++;
                b2 = merges(p1.first, b2);
                base = merges(b2, p3.second);
            }
        }
        else{
            Vertex v1;
            v1.left = -1;
            v1.counts = 1;
            v1.pl = 0;
            v1.prior = rand();
            v1.value = xi;
            v1.right = -1;
            decart.push_back(v1);
            base = merges(base, decart.size() - 1);
            counter ++;
        }
    }
    cout << decart[base].counts << endl;
    return 0;
}