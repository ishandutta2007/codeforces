#include<bits/stdc++.h>
using namespace std;
template<class T>
void read(T&x){
	x=0;char c=getchar();for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
}
template<class T>void write(T x){if(x>=10)write(x/10);putchar(x%10+'0');}
template<class T>void write(T x,char end){write(x);putchar(end);}
const int B=10;
bool can[B][B];//
int deal(int x,int y){
	for(int i=1;i<=8;i++)
		for(int j=1;j<=8;j++){
			if(i==x||j==y||abs(i-x)==abs(j-y))can[i][j]=1;
			else can[i][j]=0;
		}
}
string op;
struct cases{
	int x,y;
	bool flag;
	void move(){
		if(op=="Right")y++;
		if(op=="Left")y--;
		if(op=="Up")x--;
		if(op=="Down")x++;
		if(op=="Down-Right")x++,y++;
		if(op=="Down-Left")x++,y--;
		if(op=="Up-Left")x--,y--;
		if(op=="Up-Right")x--,y++;
	}
	void chk(){
		if(x<1||x>8||y<1||y>8){
			flag=0;
			return;
		}
		if(can[x][y]){
			flag=0;
			return;
		}
	}
}a[90];
int t;
signed main(){
	cin>>t;
	while(t--){
		vector<pair<int,int>>r;
		for(int i=1;i<=8;i++){
			if(i&1)
				for(int j=1;j<=8;j++)
					r.push_back({i,j});
			else 
				for(int j=8;j;j--)
					r.push_back({i,j});
		}
		int cnt=0;
		for(int i=1;i<=8;i++)
			for(int j=1;j<=8;j++)
				a[++cnt].flag=1,a[cnt].x=i,a[cnt].y=j;
		for(auto[x,y]:r){
			cout<<x<<" "<<y<<endl;cout.flush();
			cin>>op;if(op=="Done")break;
			for(int i=1;i<=cnt;i++)
				if(a[i].flag)a[i].move(),a[i].chk();
		}
		if(op!="Done"){
			int X=r[63].first,Y=r[63].second;
			int tot=0;
			for(int i=1;i<=cnt;i++)if(a[i].flag)tot=i;
			while(1){
				int xx=abs(X-a[tot].x),yy=abs(Y-a[tot].y);
				if(xx>yy){
					if(X>a[tot].x)X--;
					else X++;
				}else{
					if(Y>a[tot].y)Y--;
					else Y++;
				}
				cout<<X<<" "<<Y<<endl;cout.flush();
				cin>>op;if(op=="Done")break;a[tot].move();
			}
		}
		
	}
}