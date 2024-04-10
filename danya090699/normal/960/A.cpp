#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), yk=0, q[3]={0, 0, 0};
    for(int a=0; a<3; a++)
    {
        char sy='a'+a;
        while(yk<n)
        {
            if(s[yk]==sy)
            {
                q[a]++, yk++;
            }
            else break;
        }
    }
    if(q[0]+q[1]+q[2]==n and (q[2]==q[0] or q[2]==q[1]) and q[0]!=0 and q[1]!=0) cout<<"YES";
    else cout<<"NO";
}