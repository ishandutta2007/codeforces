#include<iostream>
#include<cstring>
using namespace std;
int n,minn,maxx;
int main()
{
	cin>>n;

    minn=(n/7)*2;
    maxx=(n/7)*2;
    n%=7;

    if (n>5) minn+=n-5;
    if (n>2) maxx+=2;
    else maxx+=n;
    cout<<minn<<' '<<maxx<<endl;
    return 0;
}