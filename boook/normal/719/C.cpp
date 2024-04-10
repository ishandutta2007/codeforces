#include<bits/stdc++.h>
using namespace std;
void put(string ans)
{
    int q=0,w=-1;
    for(int i=ans.size()-1;i>=0;i--){
        ans[i]+=q,q=0;
        if(ans[i]-1=='.')ans[i]='.',ans[i-1]++;
        else if(ans[i]-1=='9')q=1,ans[i]='0';
        if(w!=-1 && ans[i]==-1)ans[i]='0';
        if(w==-1 && ans[i]=='.')w=i-1;
        if(w==-1 && ans[i]!='0' && ans[i]!=-1)w=i;
    }
    if(q)printf("1");
    for(int i=0;i<=w;i++)cout<<ans[i];cout<<endl;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&m,&n)==2)
    {
        string s,ans;
        cin>>s;
        int i=0;
        while(i<s.size() && s[i]!='.')ans+=s[i],i++;
        ans+=s[i],i++;
        while(i<s.size()){
            ans+=s[i],i++;
            if(s[i-1]>='5')break;
        }
//        cout<<ans<<endl;
        int last=ans.size()-1,q=0;
        while(n){
            ans[last]+=q;q=0;
            if(ans[last-1]=='.' && ans[last]>='5')ans[last]=-1,last--,q=1,n=0;
            else if(ans[last]=='.')break;
            else if(ans[last]>='5')ans[last]=-1,q=1,n--;
            else if(ans[last]<='4')break;
            last--;
//            printf("LAST = %d\n",last);
        }
//        cout<<q<<last<<endl;
        if(last>=0)ans[last]+=q;q=0;
//        cout<<ans<<endl;
        if(q)printf("1");
        put(ans);
    }
    return 0;
}