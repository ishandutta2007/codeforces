#include<bits/stdc++.h>
using namespace std;

int n,a[200005][25],an,ad=1;
set<int> as;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        int m,k;
        cin>>m>>k;
        a[m][k]++;
    }
    for(int k=1;k<=20;k++){
        priority_queue<pair<int,int>> pq;
        for(int i=1;i<=2e5;i++){
            int s=0;
            for(int j=1;j<=20;j++)s+=min(j,k)*a[i][j];
            pq.emplace(s,i);
        }
        int s=0;
        set<int> cs;
        for(int i=0;i<k;i++){
            s+=pq.top().first;
            cs.emplace(pq.top().second);
            pq.pop();
        }
        if(s*ad>an*k){
            an=s;
            ad=k;
            as=cs;
        }
    }
    cout<<as.size()<<'\n';
    for(int x:as)cout<<x<<' ';

    return 0;
}