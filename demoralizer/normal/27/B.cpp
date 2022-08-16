#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int a[100];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,x,y;
    cin>>n;
    set<int> v[n+1][2];
    for(int i=0;i<n*(n-1)/2-1;i++){
        cin>>x>>y;
        v[x][0].insert(y);
        v[y][1].insert(x);
        a[x]++;a[y]++;
    }
    x=-1;y=-1;
    for(int i=1;i<=n;i++){
        if(a[i]<n-1){
            if(x==-1)x=i;
            else y=i;
        }
    }
    for(set<int>::iterator i=v[x][0].begin();i!=v[x][0].end();i++){
        if(v[y][1].find(*i)!=v[y][1].end()){cout<<x<<" "<<y;r0;}
    }
    x=x+y;
    y=x-y;
    x=x-y;
    for(set<int>::iterator i=v[x][0].begin();i!=v[x][0].end();i++){
        if(v[y][1].find(*i)!=v[y][1].end()){cout<<x<<" "<<y;r0;}
    }
    cout<<x<<" "<<y;
}