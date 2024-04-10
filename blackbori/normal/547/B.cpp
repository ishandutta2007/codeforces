#include <bits/stdc++.h>

using namespace std;

int Left[200003], Right[200003], Bear[200003], Ans[200003];

vector <int> V;
int N;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d",&N);

    int i,k;

    for(i=1; i<=N; i++) scanf("%d",Bear+i);

    Bear[0] = -1; Bear[N+1] = -1;
    V.clear();
    V.push_back(0);
    for(i=1; i<=N+1; i++){
        while(Bear[V.back()] > Bear[i]){
            k=V.back(); Right[k] = i-V.back();
            V.pop_back();
        }
        V.push_back(i);
    }

    V.clear();
    V.push_back(N+1);
    for(i=N; i>=0; i--){
        while(Bear[V.back()] > Bear[i]){
            k=V.back(); Left[k] = V.back()-i;
            V.pop_back();
        }
        V.push_back(i);
    }

    for(i=1; i<=N; i++){
        Ans[Left[i]+Right[i]-1] = max(Ans[Left[i]+Right[i]-1],Bear[i]);
    }

    for(i=N; i>=1; i--) Ans[i] = max(Ans[i], Ans[i+1]);
    for(i=1; i<=N; i++) printf("%d ",Ans[i]);
    printf("\n");

    return 0;
}