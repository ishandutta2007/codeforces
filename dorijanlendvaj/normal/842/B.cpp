#include <bits/stdc++.h>

using namespace std;

int n,r,d,rj;
int a,b,c;

bool onc(int ri,int xi,int yi)
{
    if ((xi*xi+yi*yi)>=(r-d+ri)*(r-d+ri) && (xi*xi+yi*yi)<=(r-ri)*(r-ri)) return true;
    return false;
}

int main()
{
	//TODO make some code
	ios_base::sync_with_stdio(0);
	cin>>r>>d>>n;
	for (int i=0;i<n;++i)
    {
        cin>>a>>b>>c;
        rj+=onc(c,a,b);
    }
    cout<<rj<<endl;
}