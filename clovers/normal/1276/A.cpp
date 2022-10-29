#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1500005;
int n; char s[N];
vector<int> v;

int main(){
    int T; scanf("%d",&T);
    while(T--){
        scanf("%s",s+1); n=strlen(s+1);
        int ans=0; v.clear();
        for(int i=1,j;i<=n-2;i=j+1){
            j=i;
            if(s[j]=='t'&&s[j+1]=='w'&&s[j+2]=='o'&&s[j+3]=='n'&&s[j+4]=='e'){
                ans++;
                v.push_back(j+2);
                j+=4;
            }
            else if(s[j]=='o'&&s[j+1]=='n'&&s[j+2]=='e'){
                ans++;
                v.push_back(j+1);
                j+=2;
            }
            else if(s[j]=='t'&&s[j+1]=='w'&&s[j+2]=='o'){
                ans++;
                v.push_back(j+1);
                j+=2;
            }
        }
        printf("%d\n",ans);
        for(int i=0;i<(int)v.size();i++) printf("%d ",v[i]);
        puts("");
    }
    return 0;
}