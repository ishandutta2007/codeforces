//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int de(int x, int y)
{
    int re=x/y;
    if(x%y>0) re++;
    return re;
}
int main()
{
    int k, q[10], su=0, yk=0, an=0;
    cin>>k;
    string s;
    cin>>s;
    for(int a=0; a<10; a++) q[a]=0;
    for(int a=0; a<s.size(); a++)
    {
        q[s[a]-'0']++, su+=s[a]-'0';
    }
    while(su<k)
    {
        if(k-su>(9-yk)*q[yk])
        {
            su+=(9-yk)*q[yk], an+=q[yk], yk++;
        }
        else
        {
            an+=de(k-su, 9-yk);
            break;
        }
    }
    cout<<an;
}