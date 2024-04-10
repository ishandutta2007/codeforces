#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <bitset>
#include <fstream>
#define int long long
#define D double
using namespace std;
struct Vertex{int left; int right; int value; int ss; int prior;};
vector<Vertex> decart;
void update(int vertex){
    if (vertex == -1){
        return;
    }
    int c = 1;
    if (decart[vertex].left != -1){
        c += decart[decart[vertex].left].ss;
    }
    if (decart[vertex].right != -1){
        c += decart[decart[vertex].right].ss;
    }
    decart[vertex].ss = c;
}
pair<int, int> split(int f, int k){
    if (f == -1){
        return make_pair(-1, -1);
    }
    int l = 0;
    if (decart[f].left != -1) l = decart[decart[f].left].ss;
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
    if (first == -1){
        return second;
    }
    if (second == -1){
        return first;
    }
    if (decart[first].prior > decart[second].prior){
        decart[first].right = merges(decart[first].right, second);
        update(first);
        return first;
    }
    decart[second].left = merges(first, decart[second].left);
    update(second);
    return second;
}
int get_left(int base, int number){
    if (base == -1) return 0;
    if (decart[base].value >= number){
        return get_left(decart[base].left, number);
    }
    int sz = 1;
    if (decart[base].left != -1){
        sz += decart[decart[base].left].ss;
    }
    return sz + get_left(decart[base].right, number);
}
int get(int base){
    if (decart[base].left == -1) return decart[base].value;
    return get(decart[base].left);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i=0; i < n; i++){
        cin >> data[i];
    }
    int base = -1;
    int answer = 0;
    for (int i=0; i < n; i++){
        int nn = get_left(base, data[i]);
        pair<int, int> p = split(base, nn);
        Vertex v = {-1, -1, data[i], 1, rand()};
        decart.push_back(v);
        int bb = merges(decart.size() - 1, p.second);
        p.second = bb;
        if (p.first != -1){
            answer += (data[i] - get(p.first));
            Vertex v1 = {-1, -1, data[i], 1, rand()};
            decart.push_back(v1);
            pair<int, int> p1 = split(p.first, 1);
            int bb1 = merges(p1.second, decart.size() - 1);
            p.first = bb1;
        }
        base = merges(p.first, p.second);
    }
    cout << answer << endl;
    return 0;
}