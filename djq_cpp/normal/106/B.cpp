#include <iostream>
using namespace std;
struct laptop{
	int speed,ram,hdd;
	int cost;
}com[101];
bool del[101];
int main(){
	int n;
	cin>>n;
	for(int k=0;k<n;k++)cin>>com[k].speed>>com[k].ram>>com[k].hdd>>com[k].cost;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	if(i!=j&&com[i].speed<com[j].speed&&com[i].ram<com[j].ram&&com[i].hdd<com[j].hdd){
		del[i]=true;
		break;
	}
	int lcost=n;
	com[n].cost=10000;
	for(int k=0;k<n;k++)
	if(!del[k]&&com[k].cost<com[lcost].cost)lcost=k;
	cout<<lcost+1;
	return 0;
}