#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod[4]={998244353,19260817,1000000007,1019260817},bas[4]={2333,1926,23333,114514};
const int D=1;
const int N=2e6+7;
struct Has
{
	int has[N][D];
	static int w[N][D];
	static void init()
	{
		for(int i=0;i<D;++i)
		{
			w[0][i]=1;
		}
		for(int i=1;i<N;++i)
		{
			for(int j=0;j<D;++j)
			{
				w[i][j]=1LL*w[i-1][j]*bas[j]%mod[j];
			}
		}
	}
	void build(string &s)
	{
		for(int i=0;i<D;++i)
		{
			has[0][i]=0;
		}
		for(int i=1;i<=s.length();++i)
		{
			for(int j=0;j<D;++j)
			{
				has[i][j]=(1LL*has[i-1][j]*bas[j]+(s[i-1]-'a'+1))%mod[j];
			}
		}
	}
	int get(int l,int r)
	{
		++l;++r;
		return (has[r][0]-1LL*has[l-1][0]*w[r-l+1][0]%mod[0]+mod[0])%mod[0];
		/*
		return make_pair((has[r][0]-1LL*has[l-1][0]*w[r-l+1][0]%mod[0]+mod[0])%mod[0],
				(has[r][1]-1LL*has[l-1][1]*w[r-l+1][1]%mod[1]+mod[1])%mod[1]);
		*/
	}
}has[21],cur;
int Has::w[N][D]={};


const int tmod=1e9+7;
const int maxn=1e5+7;
int two[maxn];
int suf[maxn][26];

ll quick(ll a,ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1) ret=ret*a%tmod;
        a=a*a%tmod;
        b>>=1;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    two[0]=1;
    for(int i=1;i<maxn;i++) two[i]=two[i-1]*2%tmod;
    cin>>n>>q;
    string s,t;
    cin>>s>>t;
    for(int i=n;i>=0;i--)
    {
        for(int j=0;j<26;j++)
            suf[i][j]=suf[i+1][j];
        if(i)
            suf[i][t[i-1]-'a']=(suf[i][t[i-1]-'a']+two[n-i])%tmod;
        //cout<<i<<":"<<suf[i][t[i-1]-'a']<<"\n";
    }
    vector<string> as;
    as.push_back(s);
    for(int i=0;i<n;i++)
    {
        if(as.back().length()>1e6) break;
        as.push_back(as.back()+t[i]+as.back());
    }
    cur.init();
    for(int i=0;i<as.size();i++)
        has[i].build(as[i]);
    while(q--)
    {
        int k;
        string T;
        cin>>k>>T;
        if(T.length()>as.back().length())
        {
            cout<<0<<'\n';
            continue;
        }
        int tar=0;
        for(int i=as.size()-1;i>=0;i--)
        {
            if(as[i].length()>=T.length())
                tar=i;
            else break;
        }
        if(k<tar)
        {
            cout<<0<<'\n';
            continue;
        }
        //cout<<tar<<" "<<as[tar]<<endl;
        cur.build(T);
        int cnt=0;
        ll ans=0;
        for(int i=T.length();i<=as[tar].length();i++)
            cnt+=cur.get(0,T.length()-1)==has[tar].get(i-T.length(),i-1);
        ans=1LL*cnt*two[k-tar]%tmod;
        vector<int> val(26);
        for(int i=0;i<T.length();i++)
        {
            //cout<<i<<":"<<cur.get(i+1,T.length()-1)<<" "<<has[tar].get(0,T.length()-i-2)<<endl;
            if((!i||cur.get(0,i-1)==has[tar].get(as[tar].length()-i,as[tar].length()-1))&&(i==T.length()-1||cur.get(i+1,T.length()-1)==has[tar].get(0,T.length()-i-2)))
                val[T[i]-'a']++;
        }
        ll inv=quick(two[n-k],tmod-2);
        for(int i=0;i<26;i++)
        {
            /*if(val[i])
            {
                cout<<i<<endl;
                cout<<suf[tar][i]<<" "<<suf[k][i]<<endl;
            }*/
            ans=(ans+1LL*val[i]*(suf[tar+1][i]-suf[k+1][i]+tmod)%tmod*inv%tmod)%tmod;
        }
        cout<<ans<<'\n';
    }

}