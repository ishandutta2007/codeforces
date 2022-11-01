#include<bits/stdc++.h>
using namespace std;
/*
 
g(h(x))=x
h(g(x))=f(x)
h(x)=f(f(x)) &&  x= f(x)

h(x)f(x)
 g(x) 
*/

int f[100000+7],g[100000+7];
int h[100000+7];
int main()
{
    int n;
    int hn=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>f[i];
    	if(f[i]==i){
    		hn++;
    		g[i]=hn;
    		h[g[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(!g[f[i]])return 0*puts("-1");
	}
	cout<<hn<<endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
	for(int i=1;i<=n;i++)cout<<g[f[i]]<<" ";
	cout<<endl;
	for(int i=1;i<=hn;i++)
	cout<<h[i]<<" ";
	return 0;
}