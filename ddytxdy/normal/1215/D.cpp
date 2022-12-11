#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,mid,mn,mx;char c[N];
int main(){
    scanf("%d%s",&n,c+1);mid=n>>1;
    for(int i=1;i<=mid;i++){
        if(isdigit(c[i]))mn+=c[i]-'0',mx+=c[i]-'0';
        else mx+=9;
    }
    for(int i=mid+1;i<=n;i++){
        if(isdigit(c[i]))mn-=c[i]-'0',mx-=c[i]-'0';
        else mn-=9;
    }
    puts(mn+mx?"Monocarp":"Bicarp");
    return 0;
}