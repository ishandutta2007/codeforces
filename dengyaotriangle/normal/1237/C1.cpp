#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=50005;

struct poi{
    int x,y,z,g,i;
};
struct pr{
    int vl,i,j,t;
};

bool operator<(pr a,pr b){
    return a.vl>b.vl;
}

int n;
poi p[maxn];
poi srt[8][maxn];

priority_queue<pr> q;
bool vis[maxn];
set<int> st;
vector<poi> vec,cvec;

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y>>p[i].z;p[i].i=i;
        vec.push_back(p[i]);
    }
    cvec=vec;vec.clear();
    sort(cvec.begin(),cvec.end(),[](poi a,poi b){
        if(a.x==b.x)return ((a.y==b.y)?(a.z<b.z):(a.y<b.y));
        return a.x<b.x;
    });
    for(int i=0;i<cvec.size();i++){
        if(cvec[i].i==-1)continue;
        if(i+1!=cvec.size()){
            if(cvec[i].x==cvec[i+1].x&&cvec[i].y==cvec[i+1].y){
                cout<<cvec[i].i<<' '<<cvec[i+1].i<<'\n';
                cvec[i+1].i=-1;
            }else vec.push_back(cvec[i]);
        }else vec.push_back(cvec[i]);
    }
    cvec=vec;vec.clear();
    sort(cvec.begin(),cvec.end(),[](poi a,poi b){
        if(a.x==b.x)return ((a.z==b.z)?(a.y<b.y):(a.z<b.z));
        return a.x<b.x;
    });
    for(int i=0;i<cvec.size();i++){
        if(cvec[i].i==-1)continue;
        if(i+1!=cvec.size()){
            if(cvec[i].x==cvec[i+1].x&&cvec[i].z==cvec[i+1].z){
                cout<<cvec[i].i<<' '<<cvec[i+1].i<<'\n';
                cvec[i+1].i=-1;
            }else vec.push_back(cvec[i]);
        }else vec.push_back(cvec[i]);
    }
    cvec=vec;vec.clear();
    sort(cvec.begin(),cvec.end(),[](poi a,poi b){
        if(a.y==b.y)return ((a.z==b.z)?(a.x<b.x):(a.z<b.z));
        return a.y<b.y;
    });
    for(int i=0;i<cvec.size();i++){
        if(cvec[i].i==-1)continue;
        if(i+1!=cvec.size()){
            if(cvec[i].z==cvec[i+1].z&&cvec[i].y==cvec[i+1].y){
                cout<<cvec[i].i<<' '<<cvec[i+1].i<<'\n';
                cvec[i+1].i=-1;
            }else vec.push_back(cvec[i]);
        }else vec.push_back(cvec[i]);
    }
    cvec=vec;vec.clear();
    sort(cvec.begin(),cvec.end(),[](poi a,poi b){
        if(a.x==b.x)return ((a.y==b.y)?(a.z<b.z):(a.y<b.y));
        return a.x<b.x;
    });
    for(int i=0;i<cvec.size();i++){
        if(cvec[i].i==-1)continue;
        if(i+1!=cvec.size()){
            if(cvec[i].x==cvec[i+1].x){
                cout<<cvec[i].i<<' '<<cvec[i+1].i<<'\n';
                cvec[i+1].i=-1;
            }else vec.push_back(cvec[i]);
        }else vec.push_back(cvec[i]);
    }
    cvec=vec;vec.clear();
    sort(cvec.begin(),cvec.end(),[](poi a,poi b){
        if(a.z==b.z)return ((a.y==b.y)?(a.x<b.x):(a.y<b.y));
        return a.z<b.z;
    });
    for(int i=0;i<cvec.size();i++){
        if(cvec[i].i==-1)continue;
        if(i+1!=cvec.size()){
            if(cvec[i].z==cvec[i+1].z){
                cout<<cvec[i].i<<' '<<cvec[i+1].i<<'\n';
                cvec[i+1].i=-1;
            }else vec.push_back(cvec[i]);
        }else vec.push_back(cvec[i]);
    }
    cvec=vec;vec.clear();
    sort(cvec.begin(),cvec.end(),[](poi a,poi b){
        if(a.y==b.y)return ((a.x==b.x)?(a.z<b.z):(a.x<b.x));
        return a.y<b.y;
    });
    for(int i=0;i<cvec.size();i++){
        if(cvec[i].i==-1)continue;
        if(i+1!=cvec.size()){
            if(cvec[i].y==cvec[i+1].y){
                cout<<cvec[i].i<<' '<<cvec[i+1].i<<'\n';
                cvec[i+1].i=-1;
            }else vec.push_back(cvec[i]);
        }else vec.push_back(cvec[i]);
    }
    cvec=vec;vec.clear();
    sort(cvec.begin(),cvec.end(),[](poi a,poi b){
        if(a.y==b.y)return ((a.x==b.x)?(a.z<b.z):(a.x<b.x));
        return a.y<b.y;
    });
    for(int i=0;i<cvec.size();i+=2){
        cout<<cvec[i].i<<' '<<cvec[i+1].i<<'\n';
    }
    /*
    for(int i=0;i<8;i++){
        memcpy(srt[i],p,sizeof(p));
        for(int j=1;j<=n;j++){
            if(i&1)srt[i][j].g+=p[j].x;
            else   srt[i][j].g-=p[j].x;
            if(i&2)srt[i][j].g+=p[j].y;
            else   srt[i][j].g-=p[j].y;
            if(i&4)srt[i][j].g+=p[j].z;
            else   srt[i][j].g-=p[j].z;
        }
        sort(srt[i]+1,srt[i]+1+n,[](poi a,poi b){
            return a.g<b.g;
        });
        for(int j=1;j<=n;j++){

        }
    }*/

    return 0;
}