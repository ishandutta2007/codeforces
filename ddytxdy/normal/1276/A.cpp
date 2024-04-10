#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int t,n;char s[N];
vector<int>ans;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s",s+1);n=strlen(s+1);ans.clear();
        for(int i=1;i<=n;i++)if(s[i]=='o')
            if(i>2&&s[i-1]=='w'&&s[i-2]=='t'||i+2<=n&&s[i+1]=='n'&&s[i+2]=='e'){
                if(i>1&&s[i-1]=='o'||i<n&&s[i+1]=='o'){
                    if(i>2&&s[i-1]=='w'&&s[i-2]=='t')ans.push_back(i-1);
                    if(i+2<=n&&s[i+1]=='n'&&s[i+2]=='e')ans.push_back(i+1);
                }
                else ans.push_back(i);
            }
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);puts("");
    }
    return 0;
}