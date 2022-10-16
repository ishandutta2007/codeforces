#include<iostream>
using namespace std;
struct node
{
	int min1,max1;
}da[35];
int main()
{  
	int d,t,uplim=0,downlim=0;
	cin>>d>>t;
	for (int i=0;i<d;i++){  
		cin>>da[i].min1>>da[i].max1;
		downlim += da[i].min1;
		uplim += da[i].max1;
	}
	if(uplim<t||downlim>t)
		cout<<"NO";
	else
	{
		cout<<"YES"<<endl;
		t -= downlim;
		for(int i=0;i<d;i++){  
			if(t>=da[i].max1-da[i].min1){  
				cout<<da[i].max1<<" ";  
				t-=da[i].max1-da[i].min1;
			}
			else if(t==0)
				cout<<da[i].min1<<" ";
			else if(t<da[i].max1-da[i].min1){
				cout<<t+da[i].min1<<" ";  
				t = 0;  
			}
		}
	}  
}