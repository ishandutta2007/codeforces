/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int N=1000;
int n;
pair<int,int> a[N+1];
void mian(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].X>>a[i].Y;
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)if(a[i].Y>a[i+1].Y){puts("NO");return;}
	puts("YES");
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		while(x<a[i].X)putchar('R'),x++;
		while(y<a[i].Y)putchar('U'),y++;
	}
	puts("");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}