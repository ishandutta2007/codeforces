#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

long long n,k;
int m;
long long p[maxn];
long long d;

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>p[i];
    }
    int cnt=0,cp=1;
    long long sp=1,ep=k;
    while(cp<=m){
        if(p[cp]-d>ep){
            sp=((p[cp]-d-1)/k)*k+1;
            ep=sp+k-1;
        }else{
            int cd=0;
            while(p[cp]-d<=ep){
                cp++;
                cd++;
                if(cp>m) break;
            }
            d+=cd;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}