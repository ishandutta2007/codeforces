#include <bits/stdc++.h>

using namespace std;

char s[55];
bool NP[55];
int n,ans=0;

int main()
{
    cin.getline(s,55);
    n=strlen(s);
    for(int i=0;i<n;i++)
    {
        if(NP[i]==1)
            continue;
        ans++;
        for(int st=i+1;st<n;st++)
        {
            bool egale=1;
            for(int j=0;j<n;j++)
            {
                if(s[(i+j)%n]!=s[(st+j)%n])
                    egale=0;
            }
            if(egale==1)
                NP[st]=1;
        }
    }
    cout<<ans;
    return 0;
}
/**


**/