#include <iostream>
#include <cstdio>
using namespace std;
int N;
const int NMax = 2005;
const int INF = 1000000005;
const long long llINF = 100000000000000005;
long long Dist[NMax];
bool Used[NMax];
int Cost[NMax][NMax], minE;
void Read(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        for(int j = i + 1; j <= N; j++){
            scanf("%d", &Cost[i][j]);
            Cost[j][i] = Cost[i][j];
        }
}
 
int findMinEdge(){
    int ans = INF;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++)
            if(i != j)
                ans = min(ans, Cost[i][j]);
    }
    return ans;
}
void subtractMinEdge(){
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            Cost[i][j] -= minE;
}
int findMinAdjacent(int node){
    int ans = INF;
    for(int i = 1; i <= N; i++)
        if(i != node)
            ans = min(ans, Cost[node][i]);
    return ans;
}
void initializeDist(){
    for(int i = 1; i <= N; i++){
        int valMin = findMinAdjacent(i);
        Dist[i] = 2LL * valMin;
    }
}
int findStartingNode(){
    long long Min = llINF;
    int ans = -1;
    for(int i = 1; i <= N; i++){
        if(!Used[i] && Dist[i] < Min){
            Min = Dist[i];
            ans = i;
        }
    }
    return ans;
}
 
void Relax(int node){
    for(int i = 1; i <= N; i++){
        if(!Used[i])
            Dist[i] = min(Dist[i], Dist[node] + Cost[node][i]);
    }
}
void runDijkstra(){
    for(int step = 1; step <= N; step++){
        int node = findStartingNode();
        Used[node] = true;
        Relax(node);
    }
}
 
void printRes(){
    for(int i = 1; i <= N; i++)
        printf("%I64d\n", Dist[i] + 1LL * (N - 1) * minE);
}
int main()
{
    Read();
    minE = findMinEdge();
    subtractMinEdge();
    initializeDist();
    runDijkstra();
    printRes();
    return 0;
}