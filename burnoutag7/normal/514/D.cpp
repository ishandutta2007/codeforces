#include<bits/stdc++.h>
using namespace std;

int n,m,k,a[100005][5];
multiset<int> s[5];

int cost(){
    int res=0;
    for(int i=0;i<m;i++){
        res+=s[i].empty()?0:*--s[i].end();
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int ans=0,sh[5]={0};
    for(int l=0,r=0;r<n;r++){
        for(int i=0;i<m;i++){
            s[i].insert(a[r][i]);
        }
        while(cost()>k){
            for(int i=0;i<m;i++){
                s[i].erase(s[i].find(a[l][i]));
            }
            l++;
        }
        if(r-l+1>ans){
            for(int i=0;i<m;i++){
                sh[i]=s[i].empty()?0:*--s[i].end();
            }
            ans=r-l+1;
        }
    }
    for(int i=0;i<m;i++){
        cout<<sh[i]<<" ";
    }

    return 0;
}