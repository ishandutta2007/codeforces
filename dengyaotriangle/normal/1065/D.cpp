#include<bits/stdc++.h>

using namespace std;

const int maxn=12;
const int dx[8]={-2,-2,-1,-1,1,1,2,2};//
const int dy[8]={-1,1,-2,2,-2,2,-1,1};//

struct pl{
    int cx,cy,ct,cv,t;
    int nxv;
};

int n;
int a[maxn][maxn];
map<pl,pair<int,int> > val;
map<pl,bool> vis;
int ix[maxn*maxn],iy[maxn*maxn];

pl mkpl(int cx,int cy,int cv,int ct,int t,int nxv){
    pl nw;
    nw.cx=cx;nw.cy=cy;nw.ct=ct;nw.cv=cv;nw.t=t;nw.nxv=nxv;
    return nw;
}

bool operator<(pl a,pl b){
    if(a.nxv==b.nxv){
        if(a.cx==b.cx){
            if(a.cy==b.cy){
                return a.t<b.t;
            }return a.cy<b.cy;
        }return a.cx<b.cx;
    }return a.nxv<b.nxv;
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            ix[a[i][j]]=i;
            iy[a[i][j]]=j;
        }
    }
    queue<pl> q;
    val[mkpl(ix[1],iy[1],0,0,1,2)]=make_pair(0,0);
    val[mkpl(ix[1],iy[1],0,0,2,2)]=make_pair(0,0);
    val[mkpl(ix[1],iy[1],0,0,3,2)]=make_pair(0,0);
    vis[mkpl(ix[1],iy[1],0,0,1,2)]=1;
    vis[mkpl(ix[1],iy[1],0,0,2,2)]=1;
    vis[mkpl(ix[1],iy[1],0,0,3,2)]=1;
    q.push(mkpl(ix[1],iy[1],0,0,1,2));
    q.push(mkpl(ix[1],iy[1],0,0,2,2));
    q.push(mkpl(ix[1],iy[1],0,0,3,2));
    int mv1=0x3f3f3f3f,mv2=0x3f3f3f3f;

    while(!q.empty()){
        pl u=q.front();q.pop();
        if(make_pair(u.cv,u.ct)>val[u]) continue;
        //cerr<<u.cx<<' '<<u.cy<<' '<<u.t<<' '<<u.cv<<' '<<u.ct<<' '<<u.nxv<<'\n';
        if(u.nxv==n*n+1){
            if(u.cv<mv1){
                mv1=u.cv;
                mv2=u.ct;
            }else if(u.cv==mv1){
                mv2=min(mv2,u.ct);
            }
            continue;
        }
        if(u.cv>mv1) break;
        for(int i=1;i<=3;i++){
            if(i==u.t) continue;
            pl nw=u;nw.t=i;nw.ct++;nw.cv++;
            pair<int,int> cr=make_pair(nw.cv,nw.ct);
            if(!vis[nw]){
                q.push(nw);
                vis[nw]=1;
                val[nw]=make_pair(nw.cv,nw.ct);
            }else if(val[nw]>cr){
                q.push(nw);
                val[nw]=cr;
            }
        }
        if(u.t==1){
            for(int i=0;i<8;i++){
                pl nw=u;
                nw.cv++;
                nw.cx+=dx[i];
                nw.cy+=dy[i];
                if(nw.cx<1||nw.cx>n||nw.cy<1||nw.cy>n) continue;
                if(nw.cx==ix[nw.nxv]&&nw.cy==iy[nw.nxv]){
                    nw.nxv++;
                }
                pair<int,int> cr=make_pair(nw.cv,nw.ct);
                if(!vis[nw]){
                    q.push(nw);
                    vis[nw]=1;
                    val[nw]=make_pair(nw.cv,nw.ct);
                }else if(val[nw]>cr){
                    q.push(nw);
                    val[nw]=cr;
                }
            }
        }else if(u.t==2){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if((int)(i==u.cx)+(int)(j==u.cy)==1){
                        pl nw=u;
                        nw.cv++;
                        nw.cx=i;nw.cy=j;
                        if(nw.cx==ix[nw.nxv]&&nw.cy==iy[nw.nxv]){
                            nw.nxv++;
                        }
                        pair<int,int> cr=make_pair(nw.cv,nw.ct);
                        if(!vis[nw]){
                            q.push(nw);
                            vis[nw]=1;
                            val[nw]=make_pair(nw.cv,nw.ct);
                        }else if(val[nw]>cr){
                            q.push(nw);
                            val[nw]=cr;
                        }
                    }
                }
            }
        }else if(u.t==3){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if((int)(i+j==u.cx+u.cy)+(int)(i-j==u.cx-u.cy)==1){
                        pl nw=u;
                        nw.cv++;
                        nw.cx=i;nw.cy=j;
                        if(nw.cx==ix[nw.nxv]&&nw.cy==iy[nw.nxv]){
                            nw.nxv++;
                        }
                        pair<int,int> cr=make_pair(nw.cv,nw.ct);
                        if(!vis[nw]){
                            q.push(nw);
                            vis[nw]=1;
                            val[nw]=make_pair(nw.cv,nw.ct);
                        }else if(val[nw]>cr){
                            q.push(nw);
                            val[nw]=cr;
                        }
                    }
                }
            }
        }
    }
    cout<<mv1<<' '<<mv2;
    return 0;
}