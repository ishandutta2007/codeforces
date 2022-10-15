#include <bits/stdc++.h>

using namespace std;

const int nax=1000+7;
int n,k,a[nax],b[nax];
string s;

bool chk(int p)
{
        bool ok=1;
        if(p-1>=1 && b[p]==b[p-1])
                ok=0;
        if(p-2>=1 && b[p]==b[p-2])
                ok=0;
        return ok;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin>>n>>k>>s;
        for(int i=1;i<=n;i++)
                a[i]=s[i-1]-'a';

        int pref=n;
        while(pref)
        {
                pref--;
                for(int i=1;i<=pref;i++)
                        b[i]=a[i];
                bool ok=1;
                for(int i=1;i<=pref;i++)
                        if(chk(i)==0)
                                ok=0;
                if(ok==0)
                        continue;
                b[pref+1]=a[pref+1]+1;
                while(!chk(pref+1))
                        b[pref+1]++;
                for(int i=pref+2;i<=n;i++)
                {
                        b[i]=0;
                        while(!chk(i))
                                b[i]++;
                }
                for(int i=1;i<=n;i++)
                        if(b[i]>=k)
                                ok=0;
                if(ok)
                {
                        for(int i=1;i<=n;i++)
                                cout<<char(b[i]+'a');
                        cout<<"\n";
                        return 0;
                }
        }
        cout<<"NO\n";
        return 0;
}