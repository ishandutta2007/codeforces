#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n=s.size();
        array<int,26> c;
        c.fill(0);
        for(char a:s) c[a-'a']++;
        int one=-1;
        int m=0;
        for(int i=0;i<26;i++)
        {
            if(c[i]==1&&one==-1) one=i;
            if(c[i]>c[m]) m=i;
        }
        if(one!=-1)
        {
            cout << char(one+'a');
            for(int i=0;i<26;i++) if(i!=one&&c[i]>0) cout << string(c[i],i+'a');
            cout << "\n";
        }
        else if(c[m]==n) cout << s << "\n";
        else
        {
            string res;
            int x=-1,y=-1,z=-1;
            for(int i=0;i<26;i++)
            {
                if(c[i]>0&&x==-1) x=i;
                else if(c[i]>0&&y==-1) y=i;
                else if(c[i]>0&&z==-1) z=i;
            }
            if(c[x]-2<=n-2-(c[x]-2))
            {
                cout << char(x+'a') << char(x+'a');
                c[x]-=2;
                string tmp;
                for(int i=0;i<26;i++) if(i!=x&&c[i]>0) tmp+=string(c[i],i+'a');
                int idx=0;
                int sz=tmp.size();
                while(idx<sz)
                {
                    cout << tmp[idx++];
                    if(c[x]>0)
                    {
                        cout << char(x+'a');
                        c[x]--;
                    }
                }
                cout << "\n";
            }
            else
            {
                cout << char(x+'a') << char(y+'a');
                c[x]--; c[y]--;
                if(z!=-1)
                {
                    cout << string(c[x],x+'a');
                    c[x]=0;
                    cout << char(z+'a');
                    c[z]--;
                    string tmp;
                    for(int i=0;i<26;i++) tmp+=string(c[i],i+'a');
                    sort(tmp.begin(),tmp.end());
                    cout << tmp << "\n";
                }
                else
                {
                    cout << string(c[y],y+'a');
                    cout << string(c[x],x+'a') << "\n";
                }
            }
        }
    }
    return 0;
}