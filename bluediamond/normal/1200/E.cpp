#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int mod=(int)1e9+9;

int add(int a,int b)
{
        a+=b;
        if(a>=mod)
                return a-mod;
        if(a<0)
                return a+mod;
        return a;
}

int mul(int a,int b)
{
        return a*(ll)b%mod;
}

int expow(int a,int b)
{
        int r=1;
        while(b)
        {
                if(b&1)
                        r=mul(r,a);
                a=mul(a,a);
                b/=2;
        }
        return r;
}

const int N=(int)1e6+7;
const int bz=62;
int n,p[N],inv[N];
char value[100];

int hsh(char ch)
{
        if('a'<=ch && ch<='z')
                return ch-'a';
        if('A'<=ch && ch<='Z')
                return ch-'A'+26;
        return ch-'0'+52;
}

int pref[N],len;

int get(int l,int r)
{
        int sm=add(pref[r],-pref[l-1]);
        return mul(sm,inv[l-1]);
}

int pref2[N],ln2;

int get2(int l,int r)
{
        int sm=add(pref2[r],-pref2[l-1]);
        return mul(sm,inv[l-1]);
}

void addup()
{
        for(int j=min(ln2,len);j>=0;j--)
        {
                int a=get(len-j+1,len);
                int b=get2(1,j);
                if(a==b)
                {
                        /// j+1...ln2
                        for(int poz=j+1;poz<=ln2;poz++)
                        {
                                len++;
                                int now=mul(get2(poz,poz),p[len-1]);
                                pref[len]=add(pref[len-1],now);
                        }
                        return;
                }
        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       // freopen("__input__","r",stdin);

        p[0]=1;
        for(int i=1;i<N;i++)
                p[i]=mul(p[i-1],bz);
        inv[N-1]=expow(p[N-1],mod-2);
        for(int j=N-2;j>=0;j--)
                inv[j]=mul(inv[j+1],bz);

        for(char c='a';c<='z';c++) value[hsh(c)]=c;
        for(char c='A';c<='Z';c++) value[hsh(c)]=c;
        for(char c='0';c<='9';c++) value[hsh(c)]=c;

        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                string w;
                cin>>w;
                ln2=w.size();
                for(int j=1;j<=ln2;j++)
                {
                        int now=mul(p[j-1],hsh(w[j-1]));
                        pref2[j]=add(pref2[j-1],now);
                }
                addup();
        }

        for(int i=1;i<=len;i++)
        {
                int nou=get(i,i);
                cout<<value[nou];
        }
        cout<<"\n";

        return 0;
}