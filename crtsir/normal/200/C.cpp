#include<bits/stdc++.h>
using namespace std;
struct Team{
	int score;
	int lost;
	int get;
	string name;
	operator <(const Team &t2)const{
		if(score!=t2.score)return score>t2.score;
		if(get-lost!=t2.get-t2.lost)return (get-lost)>(t2.get-t2.lost);
		if(get!=t2.get)return get>t2.get;
		return name<t2.name;
	}
};
Team tem[4];
int a,b,cnt;
char x[133],y[133];
bool was[4][4];
map<string,int>mp;
map<string,bool>vis;
int main(){
	for(int i=0;i<4;i++)
		tem[i].score=0,
		tem[i].lost=0,
		tem[i].get=0;
	for(int i=0;i<5;i++){
		scanf("%s %s %d:%d",&x,&y,&a,&b);
		if(!vis[x])mp[x]=cnt++,vis[x]=1;
		if(!vis[y])mp[y]=cnt++,vis[y]=1;
		if(a>b)
			tem[mp[x]].score+=3;
		else if(a==b)
			tem[mp[x]].score+=1,
			tem[mp[y]].score+=1;
		else
			tem[mp[y]].score+=3;
		tem[mp[x]].get+=a;
		tem[mp[x]].lost+=b;
		tem[mp[y]].get+=b;
		tem[mp[y]].lost+=a;
		tem[mp[x]].name=x;
		tem[mp[y]].name=y;
		was[mp[x]][mp[y]]=1;
		was[mp[y]][mp[x]]=1;
	}
	//for(int i=0;i<3;i++)
	//	for(int j=i+1;j<4;j++)
	//		cout<<tem[i].name<<' '<<tem[j].name<<' '<<was[i][j]<<endl;
	//for(int i=0;i<4;i++)
	//	cout<<tem[i].score<<' '<<tem[i].get<<' '<<tem[i].lost<<' '<<tem[i].name<<endl;
	int p1=12345,p2=0;
	for(int xx=0;xx<3;xx++)
		for(int yy=xx+1;yy<4;yy++)
			if(was[xx][yy]==0)
			{
				if(tem[yy].name =="BERLAND")swap(xx,yy);
				for(int i=0;i<100;i++)
					for(int j=0;j<i;j++)
					{
						if(i>j)
							tem[xx].score+=3;
						if(i==j)
							tem[xx].score+=1,
							tem[yy].score+=1;
						if(i<j)
							tem[yy].score+=3;
						tem[xx].get+=i;
						tem[xx].lost+=j;
						tem[yy].get+=j;
						tem[yy].lost+=i;
						//sort(tem,tem+4);
						Team tmp[4];
						for(int k=0;k<4;k++)tmp[k]=tem[k];
						sort(tmp,tmp+4);
						if(i==0&&j==1)
							for(int k=0;k<4;k++)
								cout<<tmp[k].score<<' '<<tmp[k].get<<' '<<tmp[k].lost<<' '<<tmp[k].name<<endl;
						for(int k=0;k<2;k++)
							if(tmp[k].name=="BERLAND"){
								if((i-j)<(p1-p2)||(i<p1))
								{
									p1=i,
									p2=j;
								}
	//							else
	//								cout<<i-j<<' '<<p1-p2<<endl;
							}
						//cout<<i<<' '<<j<<endl;
						if(i>j)
							tem[xx].score-=3;
						if(i==j)
							tem[xx].score-=1,
							tem[yy].score-=1;
						if(i<j)
							tem[yy].score-=3;
						tem[xx].get-=i;
						tem[xx].lost-=j;
						tem[yy].get-=j;
						tem[yy].lost-=i;
					}
					if(p1-p2<10000)
						cout<<p1<<':'<<p2;
					else
						cout<<"IMPOSSIBLE";
					return 0;
			}
}