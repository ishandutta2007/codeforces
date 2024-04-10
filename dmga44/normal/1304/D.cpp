#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        ll a1=2*n,a2=2*n;
        vector<ll>r1,r2;
        set<ll> s1,s2;
        r1.push_back(a1);
        r2.push_back(a2);
        s1.insert(a1);
        s2.insert(a2);
        map<ll,int> m1,m2;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='>')
            {
                a1-=2*n;
                a2--;
            }
            else
            {
                a1++;
                a2+=2*n;
            }
            r1.push_back(a1);
            r2.push_back(a2);
            s1.insert(a1);
            s2.insert(a2);

        }

        int cont=1;
        for(auto y : s1)
        {
            m1[y]=cont;
            cont++;
        }

        cont=1;
        for(auto y : s2)
        {
            m2[y]=cont;
            cont++;
        }

        for(int i=0;i<n;i++)
            cout << m1[r1[i]] << ' ';
        cout << '\n';
        for(int i=0;i<n;i++)
            cout << m2[r2[i]] << ' ';
        cout << '\n';


//        int ant=0;
//        vector<int> r1,r2;
//        for(int i=0;i<n-1;i++)
//        {
//            if(i && s[i]=='>' && s[i-1]=='<')
//            {
//                int p=i-1;
//                while(p>=0 && s[p]=='<')
//                    p--;
//                p++;
//
//                for(int j=ant;j<=p;j++)
//                    r1.push_back(n-i-(i-p));
//                for(int j=0;j<i-p;j++)
//                    r1.push_back(n-i+p-ant+1);
//                ant=i;
//            }
//        }
//        int p=n-1;
//        while(p>=0 && s[p]=='<')
//            p--;
//        p++;
//
//        for(int j=ant;j<=p;j++)
//            r1.push_back(1-(i-p));
//        for(int j=0;j<i-p;j++)
//            r1.push_back(1+p-ant+1);
//        ant=n-1;
    }

    return 0;
}