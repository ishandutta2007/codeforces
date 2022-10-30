#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#define mp make_pair
#define pb push_back
using namespace std;
string s[110000];
int n;
char ts[1100000];
int len[110000],cnt[110000];
char last[110000];
vector<int> aa[1100000];
vector<int> a[30];
vector<pair<int,int> > save;
void getstr(string &s)
{
    scanf("%s",ts);
    int len=strlen(ts);
    s="";
    for(int i=0;i<len;i++)s+=ts[i];
}
bool vowel(char c)
{
    if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return 1;
    return 0;
}
bool cmp(pair<int,int> x,pair<int,int> y)
{
    int t1=0,t2=0;
    if (last[x.first]==last[x.second])t1=1;
    if (last[y.first]==last[y.second])t2=1;
    return t1>t2;
}
struct node{ int a,b,c,d; };
vector<node> ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        getstr(s[i]);
        len[i]=s[i].length();
        for(int j=0;j<len[i];j++)cnt[i]+=vowel(s[i][j]);
        for(int j=0;j<len[i];j++)if (vowel(s[i][j]))last[i]=s[i][j];
        aa[cnt[i]].pb(i);
    }
    for(int i=1;i<=1000000;i++)
    {
        for(int c=0;c<26;c++)a[c].clear();
        for(auto p:aa[i]){ a[last[p]-'a'].pb(p); }
        static vector<int> tmp; tmp.clear();
        for(int c=0;c<26;c++)
        {
            int cnt=a[c].size();
            if (cnt%2==1)tmp.pb(a[c][cnt-1]);
            for(int j=0;j+1<cnt;j+=2)save.pb(mp(a[c][j],a[c][j+1]));
        }
        int cnt=tmp.size();
        for(int j=0;j+1<cnt;j+=2)save.pb(mp(tmp[j],tmp[j+1]));
    }
    sort(save.begin(),save.end(),cmp);
    int head=0,tail=save.size()-1;
    while (head<tail)
    {
        if (last[save[head].first]!=last[save[head].second])break;
        ans.pb({save[tail].first,save[tail].second,save[head].first,save[head].second});
        head++; tail--;
    }
    cout<<ans.size()<<endl;
    for(auto p:ans)cout<<s[p.a]<<' '<<s[p.c]<<endl<<s[p.b]<<' '<<s[p.d]<<endl;
}