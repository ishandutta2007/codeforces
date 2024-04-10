#include<bits/stdc++.h>
using namespace std;

int h,w,sx,sy,m,a[10];
vector<vector<vector<int>>> g;
vector<int> s;

void expand(int x){
    int r=g.size();
    for(int i=1;i<x;i++)if(i&1){
        for(int j=r-1;~j;j--)g.emplace_back(g[j]);
    }else{
        for(int j=0;j<r;j++)g.emplace_back(g[j]);
    }
    for(int i=0;i<g.size();i++){
        for(int j=0;j<a[1];j++){
            g[i][j].emplace_back(i/r+1);
        }
    }
}

void flip(){
    vector<vector<vector<int>>> ng(w,vector<vector<int>>(h));
    for(int i=0;i<h;i++)for(int j=0;j<w;j++){
        ng[j][i]=g[i][j];
    }
    swap(g,ng);
    swap(h,w);
    swap(sx,sy);
}

void up(int &x,int &y){
    vector<int> &v=g[x][y],&nv=g[--x][y];
    for(int i=0;i<m;i++){
        if(v[i]!=nv[i]){
            cout<<(nv[i]>v[i]?"inc ":"dec ")<<i+1<<'\n';
            break;
        }
    }
}

void down(int &x,int &y){
    vector<int> &v=g[x][y],&nv=g[++x][y];
    for(int i=0;i<m;i++){
        if(v[i]!=nv[i]){
            cout<<(nv[i]>v[i]?"inc ":"dec ")<<i+1<<'\n';
            break;
        }
    }
}

void left(int &x,int &y){
    vector<int> &v=g[x][y],&nv=g[x][--y];
    for(int i=0;i<m;i++){
        if(v[i]!=nv[i]){
            cout<<(nv[i]>v[i]?"inc ":"dec ")<<i+1<<'\n';
            break;
        }
    }
}

void right(int &x,int &y){
    vector<int> &v=g[x][y],&nv=g[x][++y];
    for(int i=0;i<m;i++){
        if(v[i]!=nv[i]){
            cout<<(nv[i]>v[i]?"inc ":"dec ")<<i+1<<'\n';
            break;
        }
    }
}

void cycle(){
    cout<<"Cycle\n";
    int x=sx,y=sy;
    do{
        if(x==h-1){
            if(y==w-1)up(x,y);
            else right(x,y);
        }else{
            if(y&1){
                if(x)up(x,y);
                else left(x,y);
            }else{
                if(x<h-2)down(x,y);
                else if(y)left(x,y);
                else down(x,y);
            }
        }
    }while(x!=sx||y!=sy);
}

void rotate(){
    vector<vector<vector<int>>> ng(w,vector<vector<int>>(h));
    for(int i=0;i<h;i++)for(int j=0;j<w;j++){
        ng[j][h-1-i]=g[i][j];
    }
    swap(g,ng);
    swap(h,w);
    swap(sx,sy);
    sy=w-1-sy;
}

void corner(){
    while(sx!=0||sy!=0)rotate();
    for(int i=0;i<h;i++){
        if(i&1)for(int j=1;j<w;j++)left(sx,sy);
        else for(int j=1;j<w;j++)right(sx,sy);
        if(i+1!=h)down(sx,sy);
    }
}

void border(){
    while(sx!=0)rotate();
    int x=sx,y=sy;
    while(y){
        if(y&1){
            if(x)up(x,y);
            else left(x,y);
        }else{
            if(x<h-2)down(x,y);
            else left(x,y);
        }
    }
    while(x<h-1)down(x,y);
    while(y<w-1)right(x,y);
    while(x!=h-2||y!=sy+1){
        if(y&1){
            if(x<h-2)down(x,y);
            else left(x,y);
        }else{
            if(x)up(x,y);
            else left(x,y);
        }
    }
}

void even(){
    int x=sx,y=sy;
    while(x){
        if(x&1){
            if(y<w-1)right(x,y);
            else up(x,y);
        }else{
            if(y>sy)left(x,y);
            else up(x,y);
        }
    }
    while(y>=sy)left(x,y);
    while(y){
        if(y&1){
            if(x)up(x,y);
            else left(x,y);
        }else{
            if(x<sx)down(x,y);
            else left(x,y);
        }
    }
    while(x<h-1)down(x,y);
    right(x,y);
    while(x!=h-1||y!=w-1){
        if(y&1){
            if(x-1>sx)up(x,y);
            else right(x,y);
        }else{
            if(x+1<h)down(x,y);
            else right(x,y);
        }
    }
}

void odd(){
    int x=sx,y=sy;
    while(x<h-1)down(x,y);
    while(y)left(x,y);
    up(x,y);
    while(x>=sx){
        if(x&1){
            if(y<sy-1)right(x,y);
            else up(x,y);
        }else{
            if(y)left(x,y);
            else up(x,y);
        }
    }
    while(y<=sy){
        if(y&1){
            if(x<sx-1)down(x,y);
            else right(x,y);
        }else{
            if(x)up(x,y);
            else right(x,y);
        }
    }
    while(x||y!=w-1){
        if(y&1){
            if(x<h-1)down(x,y);
            else right(x,y);
        }else{
            if(x)up(x,y);
            else right(x,y);
        }
    }
}

void path(){
    cout<<"Path\n";
    if((sx==0||sx==h-1)&&(sy==0||sy==w-1))corner();
    else if(sx==0||sx==h-1||sy==0||sy==w-1)border();
    else if(sx&1)even();
    else odd();
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>m;
    for(int i=0;i<m;i++)cin>>a[i];
    s.resize(m);
    for(int &x:s)cin>>x;
    if(m==1){
        if(*a==2){
            cout<<"Cycle\n";
            if(s.front()==1)cout<<"inc 1\ndec 1\n";
            else cout<<"dec 1\ninc 1\n";
        }else if(s.front()==1||s.front()==*a){
            cout<<"Path\n";
            if(s.front()==1){
                while(--*a)cout<<"inc 1\n";
            }else{
                while(--*a)cout<<"dec 1\n";
            }
        }else{
            cout<<"No\n";
        }
        return 0;
    }
    for(int i=1;i<=a[0];i++){
        g.emplace_back();
        for(int j=1;j<=a[1];j++){
            g.back().emplace_back(vector<int>{i,j});
        }
    }
    for(int i=2;i<m;i++)expand(a[i]);
    h=g.size();
    w=a[1];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(g[i][j]==s){
                sx=i,sy=j;
                break;
            }
        }
    }
    if(w&1^1){
        cycle();
    }else if(h&1^1){
        flip();
        cycle();
    }else if(sx+sy&1){
        cout<<"No\n";
    }else path();

    return 0;
}