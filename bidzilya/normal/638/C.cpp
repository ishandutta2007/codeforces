#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

struct TEdge {
    int From;
    int To;
    int Next;
    int Prev;
    int Index;
    int ListIndex;
    int RevListIndex;
};

vector<int> head;
vector<TEdge> edges;

void AddEdges(int from, int to, int index) {
    int fwdListIndex = edges.size();
    int bckwListIndex = edges.size() + 1;

    if (head[from] != -1) {
        edges[head[from]].Prev = fwdListIndex;
    }
    edges.push_back(TEdge{from, to, head[from], -1, index, fwdListIndex, bckwListIndex});
    head[from] = fwdListIndex;

    if (head[to] != -1) {
        edges[head[to]].Prev = bckwListIndex;
    }
    edges.push_back(TEdge{to, from, head[to], -1, index, bckwListIndex, fwdListIndex});
    head[to] = bckwListIndex;
}

void DeleteEdge(int listIndex) {
    int prev = edges[listIndex].Prev;
    int next = edges[listIndex].Next;
    if (prev != -1) {
        edges[prev].Next = next;
    }
    if (next != -1) {
        edges[next].Prev = prev;
    }
    int vert = edges[listIndex].From;
    if (head[vert] == listIndex) {
        head[vert] = next;
    }
}

vector<int> degree;
set<pair<int, int>> degrees;

vector<vector<int>> result;

set<pair<int, int>> usedTime;
vector<int> lastTime;

void DecDegree(int vert) {
    degrees.erase(degrees.find(make_pair(degree[vert], vert)));
    --degree[vert];
    if (degree[vert] != 0) {
        degrees.insert(make_pair(degree[vert], vert));
    }
}

void DeleteEdges(int listIndex) {
    int from = edges[listIndex].From;
    int to = edges[listIndex].To;

    DecDegree(from);
    DecDegree(to);

    int revListIndex = edges[listIndex].RevListIndex;
    DeleteEdge(listIndex);
    DeleteEdge(revListIndex);
}

void Do() {
    if (degrees.empty()) {
        return;
    }

    int from = degrees.begin()->second;
    int listIndex = head[from];
    int index = edges[listIndex].Index;
    int to = edges[listIndex].To;

    DeleteEdges(listIndex);

    Do();

    while (usedTime.find(make_pair(lastTime[to], to)) != usedTime.end()) {
        ++lastTime[to];
    }
    while (usedTime.find(make_pair(lastTime[from], from)) != usedTime.end()) {
        ++lastTime[from];
    }

    int curTime = max(lastTime[to], lastTime[from]);

    while (curTime >= result.size()) {
        result.push_back(vector<int>());
    }

    usedTime.insert(make_pair(curTime, from));
    usedTime.insert(make_pair(curTime, to));

    result[curTime].push_back(index);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    head.assign(n, -1);
    degree.assign(n, 0);
    for (int i = 0; i + 1 < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        AddEdges(v1, v2, i);
        ++degree[v1];
        ++degree[v2];
    }

    for (int i = 0; i < n; ++i) {
        degrees.insert(make_pair(degree[i], i));
    }

    lastTime.assign(n, 0);
    Do();

    cout << result.size() << endl;
    for (const vector<int>& x : result) {
        cout << x.size() << " ";
        for (int y : x) {
            cout << y + 1 << " ";
        }
        cout << '\n';
    }
    cout.flush();

    return 0;
}