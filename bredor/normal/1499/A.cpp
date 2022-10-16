// 228
#include <iostream>

using namespace std;

int main()
{
int n,t,f,s,w,b;cin>>t;
for(int i=0;i<t;i++){
cin>>n>>f>>s>>w>>b;if((f+s)/2>=w&&(2*n-f-s)/2>=b)cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}
}