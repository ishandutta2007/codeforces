#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=1005;

int n;
int a[maxn][maxn];
int b[maxn][maxn];

map<pair<char,char>,char > trans;

int main(){
    trans[{'D','C'}]='-';
    trans[{'U','C'}]='+';
    trans[{'L','C'}]='L';
    trans[{'R','C'}]='R';
    trans[{'-','C'}]='D';
    trans[{'+','C'}]='U';

    trans[{'D','I'}]='D';
    trans[{'U','I'}]='U';
    trans[{'L','I'}]='+';
    trans[{'R','I'}]='-';
    trans[{'-','I'}]='R';
    trans[{'+','I'}]='L';

    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int _m;
        cin>>n>>_m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];a[i][j]--;
            }
        }
        string op;
        cin>>op;
        string st="";
        int lr=0,ud=0,pm=0;
        for(char x:op){
            if(x=='I'||x=='C'){
                if(!st.empty()&&st.back()==x)st.pop_back();
                else st.push_back(x);
                if(st.size()==6)st.clear();
            }else{
                char cur=x;
                for(int i=(int)st.size()-1;i>=0;i--){
                    cur=trans[make_pair(cur,st[i])];
                }
                if(cur=='+')pm++;
                else if(cur=='-')pm--;
                else if(cur=='L')lr++;
                else if(cur=='R')lr--;
                else if(cur=='D')ud--;
                else if(cur=='U')ud++;
            }
            //cerr<<st<<endl;
        }
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]=((a[i][j]-pm)%n+n)%n;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++){
            b[i][j]=a[i][((j+lr)%n+n)%n];
        }
        for(int i=0;i<n;i++)for(int j=0;j<n;j++){
            a[i][j]=b[((i+ud)%n+n)%n][j];
        }
        for(int i=0;i<st.size();i++){
            if(st[i]=='C'){
                for(int i=0;i<n;i++)for(int j=0;j<n;j++)b[a[i][j]][j]=i;
                for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]=b[i][j];
            }else if(st[i]=='I'){
                for(int i=0;i<n;i++)for(int j=0;j<n;j++)b[i][a[i][j]]=j;
                for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]=b[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)cout<<a[i][j]+1<<' ';
            cout<<'\n';
        }
        if(t)cout<<'\n';
    }
    return 0;
}