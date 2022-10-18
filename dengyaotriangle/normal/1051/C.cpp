#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

int n;
int cnt[maxn];
int x[maxn];
vector<int> idx[maxn];
char ans[maxn];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        cnt[x[i]]++;
        idx[x[i]].push_back(i);
    }
    int c1=0,c2=0,c3=0;
    for(int i=1;i<maxn;i++){
        if(cnt[i]==1){
            c1++;
        }else if(cnt[i]==2){
            c2++;
        }else if(cnt[i]>2){
            c3++;
        }
    }
    if(c1%2==1&&c3==0){
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    bool id=0;
    for(int i=1;i<maxn;i++){
        if(cnt[i]==1){
            ans[idx[i][0]]=(id?'A':'B');
            id=!id;
        }else if(cnt[i]==2){
            ans[idx[i][0]]='A';
            ans[idx[i][1]]='B';
        }
    }
    for(int i=1;i<maxn;i++){
        if(cnt[i]>2){
            if(id){
                ans[idx[i][0]]='A';
                id=!id;
            }else{
                ans[idx[i][0]]='B';
            }
            for(int j=1;j<idx[i].size();j++) ans[idx[i][j]]='B';
        }
    }
    cout<<(ans+1);
    return 0;
}