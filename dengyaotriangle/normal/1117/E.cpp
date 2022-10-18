#include<bits/stdc++.h>

using namespace std;

const int maxn=10005;

char t[maxn],ans[maxn];
int n;
char p[4][maxn];
char r[4][maxn];

int main(){
    cin>>(t+1);
    n=strlen(t+1);
    for(int i=1;i<=n;i++){
        p[0][i]=i%26+'a';
        p[1][i]=(i/26)%26+'a';
        p[2][i]=(i/26/26)%26+'a';
    }
    cout<<"? "<<(p[0]+1)<<endl;
    cout<<"? "<<(p[1]+1)<<endl;
    cout<<"? "<<(p[2]+1)<<endl;
    fflush(stdout);
    cin>>(r[0]+1)>>(r[1]+1)>>(r[2]+1);
    for(int i=1;i<=n;i++){
        int ps=(r[2][i]-'a')*26*26+(r[1][i]-'a')*26+r[0][i]-'a';
        ans[ps]=t[i];
    }
    cout<<"! "<<(ans+1);
    fflush(stdout);
    return 0;

}