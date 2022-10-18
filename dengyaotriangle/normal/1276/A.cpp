#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=150015;

int n;
char c[maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>(c+1);n=strlen(c+1);
        vector<int> rm;
        for(int i=1;i<=n;i++){
            if(c[i]=='o'&&c[i+1]=='n'&&c[i+2]=='e'){rm.push_back(i+1);c[i+1]=' ';}
            else if(c[i]=='t'&&c[i+1]=='w'&&c[i+2]=='o'&&c[i+3]=='n'&&c[i+4]=='e'){
                rm.push_back(i+2);c[i+2]=' ';
            }else if(c[i]=='t'&&c[i+1]=='w'&&c[i+2]=='o'){rm.push_back(i+1);c[i+1]==' ';}
        }
        cout<<rm.size()<<'\n';
        for(int i=0;i<rm.size();i++){cout<<rm[i]<<' ';}cout<<'\n';
    }
    return 0;
}