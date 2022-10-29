#include<bits/stdc++.h>
using namespace std;
const int N=3000005;

char s[N],a[N],b[N];
int match[30],n,k,bl[30],pos;
vector<int> T; 

bool check(int now,int flag)//1:big 0:small
{
    T.clear();
    for(int i=now+1;i<=n;i++)
    {
        pos=i;
        if(match[s[i]-'a']!=-1)
        {
            if(flag==1)
            {
                if(match[s[i]-'a']<a[i]-'a') return 0;
                if(match[s[i]-'a']>a[i]-'a') return 1;
            }
            else
            {
                if(match[s[i]-'a']<b[i]-'a') return 1;
                if(match[s[i]-'a']>b[i]-'a') return 0;
            }
        }
        else
        {
            int tmp=-1;
            for(int j=0;j<k;j++) if(!bl[j])   
            {
                if(flag==1)
                {
                    if(j>a[i]-'a') {match[s[i]-'a']=j; T.push_back(s[i]-'a'); bl[j]=1; return 1;}
                    if(j==a[i]-'a') tmp=j;
                }
                else
                {
                    if(j<b[i]-'a') {match[s[i]-'a']=j; T.push_back(s[i]-'a'); bl[j]=1; return 1;}
                    if(j==b[i]-'a') tmp=j;
                }
            }
            if(tmp==-1) return 0;
            else match[s[i]-'a']=tmp, T.push_back(s[i]-'a'), bl[tmp]=1;
        }
    }
    return 1;
}

void back()
{
    for(int i=0;i<(int)T.size();i++)
    {
        int to=T[i]; bl[match[to]]=0; match[to]=-1;
    }
    T.clear();
}

bool bigg()
{
    for(int i=1;i<=n;i++) 
    {
        if(a[i]>b[i]) return 1;
        else if(a[i]<b[i]) return 0;
    }
    return 0;
}

void solve()
{
    scanf("%d",&k); scanf("%s",s+1); n=strlen(s+1);
    for(int i=0;i<k;i++) match[i]=-1,bl[i]=0;
    scanf("%s",a+1); scanf("%s",b+1);
    if(bigg()) swap(a,b);
    for(int i=1;i<=n;i++) 
    {
        pos=i;
        if(a[i]==b[i])
        {
            if(match[s[i]-'a']==-1&&bl[a[i]-'a']) 
            {
                puts("NO");
                return;
            }
            if(match[s[i]-'a']==-1) match[s[i]-'a']=a[i]-'a',bl[a[i]-'a']=1;
            else if(match[s[i]-'a']!=a[i]-'a') 
            {
                puts("NO");
                return;
            }
        }
        else
        {
            int flag=-1;
            if(match[s[i]-'a']!=-1)
            {
                int tmp=match[s[i]-'a'];
                if(tmp<a[i]-'a'||tmp>b[i]-'a')
                {
                    puts("NO");
                    return;
                }
                else if(tmp==a[i]-'a') {
                    if(!check(i,1)) {puts("NO"); return;}
                    break;
                }
                else if(tmp==b[i]-'a') {
                    if(!check(i,0)) {puts("NO"); return;}
                    break;
                }
                else break;
            }
            else
            {
                int tmp=-1;
                for(int j=0;j<k;j++) if(!bl[j])
                {
                    //cout<<a[i]-'a'<<" "<<b[i]-'a'<<endl;
                    if(j<a[i]-'a'||j>b[i]-'a') continue;
                    if(j==a[i]-'a') 
                    {
                        match[s[i]-'a']=j; bl[j]=1;
                        if(check(i,1)) {tmp=j; break;}
                        match[s[i]-'a']=-1; bl[j]=0;
                        back();
                    }
                    else if(j==b[i]-'a')
                    {
                        match[s[i]-'a']=j; bl[j]=1;
                        if(check(i,0)) {tmp=j; break;}
                        match[s[i]-'a']=-1; bl[j]=0;
                        back();
                    }
                    else {tmp=j; break;}
                } 
                //cout<<tmp<<endl;
                if(tmp>=0) {match[s[i]-'a']=tmp; bl[tmp]=1; break;}
                else 
                {
                    puts("NO");
                    return;
                }
            }
        }
    }
    vector<int> v; v.clear();
    for(int i=0;i<k;i++) if(!bl[i]) v.push_back(i);
    for(int i=0;i<k;i++) if(match[i]==-1) match[i]=v.back(), v.pop_back();
    puts("YES");
    for(int i=0;i<k;i++) printf("%c",match[i]+'a');
    puts("");
}

int main()
{
    int TTT; cin>>TTT;
    while(TTT--){solve();}
    return 0;
}