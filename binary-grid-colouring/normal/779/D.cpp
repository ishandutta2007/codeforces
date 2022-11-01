#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200010];
string s,p;
int check(int n)
{
    string tmp=s;
    for (int i=0; i<n; i++)
    {
        tmp[a[i] - 1] = '*';
    }
    int i=0,j=0;
    while (i < s.length() && j < p.length() )
    {
        if (tmp[i] != p[j]) i++;
        else{
            i++;
            j++;
        }
    }
    if(j==p.length())return 1;
    else return 0;
}

int main()
{
    cin>>s>>p;
    for (int i = 0; i < s.length(); i++) cin>>a[i];
   	int l=0;
	int r=s.length()-1;
    int ans=0;
    while (l<=r)
    {
        int mid = (l+r)>>1;
        if (check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}