#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    char c[n][m];
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    set<pair<int,int> >s;
    for(int i=0;i<n;i++){
        int k=0;
        for(int j=0;j<m;j++){
            if(c[i][j]=='B')s.insert({i,j});
            if(k==0&&c[i][j]=='B'){
                k=1;
            }
            if(k==1&&c[i][j]=='W'){
                k=2;
            }
            if(k==2&&c[i][j]=='B'){
                cout<<"NO";r0;
            }
        }
    }
    for(int j=0;j<m;j++){
        int k=0;
        for(int i=0;i<n;i++){
            if(k==0&&c[i][j]=='B'){
                k=1;
            }
            if(k==1&&c[i][j]=='W'){
                k=2;
            }
            if(k==2&&c[i][j]=='B'){
                cout<<"NO";r0;
            }
        }
    }
    set<pair<int,int> >::iterator i,j;
    int k=0;
    for(i=s.begin();i!=s.end();i++){
        j=s.begin();
        for(int z=0;z<=k;z++)j++;
        for(;j!=s.end();j++){
            int a=(*i).fr,b=(*i).sc,c=(*j).fr,d=(*j).sc;
            if(s.find({a,d})==s.end())
                if(s.find({c,b})==s.end()){
                    cout<<"NO";r0;
                }
        }
        k++;
    }
    cout<<"YES";
}