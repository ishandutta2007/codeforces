#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <ctime>

using namespace std;

char str[100005],sym[502];
int l[502],r[502],k,L,R;

int check()
{
    int n=strlen(str),ans=0;
    for(int rr=0;rr<n;rr++)
    {
        int ans1=0;
        for(int ll=0;ll<=rr;ll++)
        {
            int cnt=0;
            for(int i=0;i<k;i++)
            {
                int num=0;
                for(int j=ll;j<=rr;j++)
                    num+=str[j]==sym[i];
                if (num>=l[i]&&num<=r[i]) cnt++;
            }
            if (cnt>=L&&cnt<=R) ans1++;
        }
        cout << rr << " " << ans1 << endl;
        ans+=ans1;
    }
    return ans;
}

vector <int> let[26];
/*
int get(int len,int n)
{
    sort(v,v+len);
    int cnt=0,sum=0,ind=0;
    for(int i=0;i<len;++i)
    {
        if (sum>=L&&sum<=R)
        {
            cnt+=v[i].first-ind;
        }
        sum-=v[i].second;
        ind=v[i].first;
        while(i+1<len&&v[i]==v[i+1])
        {
            ++i;
            sum-=v[i].second;
            ind=v[i].first;
        }
    }
    if (sum>=L&&sum<=R) cnt+=n-ind+1;
    return cnt;
}*/

long long solve()
{
    pair <int,int> v[1002];
    int n=strlen(str); long long ans=0;
    for(int i=0;i<26;i++)
        let[i].push_back(0);
    for(int i=0;i<n;++i)
    {
        let[str[i]-'a'].push_back(i+1);
        int len=0;
        for(int j=0;j<k;++j)
        {
            if (let[sym[j]-'a'].size()<l[j]+1) continue;
    //      cout << ((let[sym[j]-'a'].size())>=r[j]+1 ? (let[sym[j]-'a'].size()-r[j]-1) : 0) << endl;
            int ind=((int)let[sym[j]-'a'].size()-r[j]-1);
            if (ind<0) ind=0;
            int ll=let[sym[j]-'a'][ind],rr=l[j]==0 ? i+1 : let[sym[j]-'a'][let[sym[j]-'a'].size()-l[j]];
            if (ll<=rr)
            {
                v[len++]=make_pair(ll,-1);
                v[len++]=make_pair(rr,1);
            }
        }
//      cout << i << "  " << get(v,i) << endl;
//      ans+=get(len,i);
        sort(v,v+len);
        int sum=0,ind=0;
        for(int j=0;j<len;++j)
        {
            if (sum>=L&&sum<=R)
                ans+=v[j].first-ind;
            sum-=v[j].second;
            ind=v[j].first;
            while(j+1<len&&v[j]==v[j+1])
            {
                ++j;
                sum-=v[j].second;
                ind=v[j].first;
            }
        }
        if (sum>=L&&sum<=R) ans+=i-ind+1;
    }
    return ans;
}

int Cur;

struct item{
    item(int _pos = 0,int _ind = 0,int _type = 0) : pos(_pos), ind(_ind), type(_type) {};
    int pos,ind,type;
    int getIndex()
    {
        if (pos<0) return pos;
        if (pos<let[sym[ind]-'a'].size()) return let[sym[ind]-'a'][pos]+1;
        return Cur+(type==-1);
    }
};

bool operator < (item & a,item & b)
{
    return a.getIndex()<b.getIndex()||a.getIndex()==b.getIndex()&&a.type>b.type;
}

long long solve2()
{
    item v[1002];
    int n=strlen(str); long long ans=0;
//  for(int i=0;i<26;i++)
//      let[i].push_back(0);
    for(int i=0;i<k;i++) {
        v[2*i]=item(-r[i]-1,i,1);
        v[2*i+1]=item(-l[i],i,-1);
    }
    for(int i=0;i<n;++i) {
        Cur=i;
        let[str[i]-'a'].push_back(i);
        for(int j=0;j<2*k;j++) {
            if (sym[v[j].ind]==str[i])
                v[j].pos++;
        }
        for(int j=2*k-1;j>=0;j--) {
            for(int t=j+1;t<2*k;t++) {
                if (v[t]<v[t-1]) swap(v[t-1],v[t]);
                else break;
            }
        }
        int ans1=0,sum=0,ind=0,index;
//      for(int j=0;j<2*k;j++)
//          cout << v[j].getIndex() << "    " << v[j].type << endl;
        int was[502]={0};
        memset(was,1,sizeof(was));
        for(int j=0;j<2*k;j++) {
            was[v[j].ind]*=-1;
            if (v[j].type==was[v[j].ind]) continue;
            index=v[j].getIndex();
            if (sum>=L&&sum<=R&&index>=0) ans1+=index-ind;
            sum+=v[j].type;
            if (index>=0) ind=index;
            while(j+1<2*k&&v[j+1].getIndex()==index&&v[j+1].type==v[j].type) {
                sum+=v[j].type,j++;
            }
        }
        if (sum>=L&&sum<=R) ans1+=i-ind+1;
//      cout << i << "  " << ans1 << endl;
        ans+=ans1;
    }
    return ans;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    gets(str);
    int n=strlen(str);
    cin >> k >> L >> R;
    for(int i=0;i<k;i++)
        cin >> sym[i] >> l[i] >> r[i];
//  cout << check() << endl;
    cout << solve2() << endl;
    return 0;
}