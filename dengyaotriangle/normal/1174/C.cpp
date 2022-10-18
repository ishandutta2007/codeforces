#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=100005;

int n;
int col[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    int c=0;
    for(long long i=2;i<=n;i++){
        if(!col[i]){
            ++c;
            col[i]=c;
            for(long long j=i*i;j<=n;j+=i)col[j]=c;
        }
    }
    for(int i=2;i<=n;i++)cout<<col[i]<<' ';
    return 0;
}