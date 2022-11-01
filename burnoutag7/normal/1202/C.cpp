#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int offset=200000;

string s;
int upDown[400005];
int leftRight[400005];
int curX,curY;
int minX,minY,maxX,maxY;
int cntPassX,cntPassY;
bool fromDownX,fromUpX,fromLeftY,fromRightY;

inline void moveUp(){
    curX++;
    if(fromDownX&&maxX==curX){
        cntPassX++;
        fromDownX=0;
    }
    if(maxX==curX){
        fromUpX=1;
    }
    if(curX>maxX){
        fromDownX=0;
        cntPassX=1;
        fromUpX=1;
        maxX=curX;
    }
}

inline void moveDown(){
    curX--;
    if(fromUpX&&minX==curX){
        cntPassX++;
        fromUpX=0;
    }
    if(minX==curX){
        fromDownX=1;
    }
    if(curX<minX){
        fromUpX=0;
        cntPassX=1;
        fromDownX=1;
        minX=curX;
    }
}

inline void moveRight(){
    curY++;
    if(fromLeftY&&maxY==curY){
        cntPassY++;
        fromLeftY=0;
    }
    if(maxY==curY){
        fromRightY=1;
    }
    if(curY>maxY){
        fromLeftY=0;
        cntPassY=1;
        fromRightY=1;
        maxY=curY;
    }
}

inline void moveLeft(){
    curY--;
    if(fromRightY&&minY==curY){
        cntPassY++;
        fromRightY=0;
    }
    if(minY==curY){
        fromLeftY=1;
    }
    if(curY<minY){
        fromRightY=0;
        cntPassY=1;
        fromLeftY=1;
        minY=curY;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>s;

        minX=minY=maxX=maxY=curX=curY=0;
        cntPassX=cntPassY=0;
        fromUpX=fromDownX=fromLeftY=fromRightY=true;

        for(int i=0;i<s.size();i++){
            if(s[i]=='W'){
                moveUp();
            }
            if(s[i]=='A'){
                moveLeft();
            }
            if(s[i]=='S'){
                moveDown();
            }
            if(s[i]=='D'){
                moveRight();
            }
        }

        ll ansX=(ll(maxX-minX+1)-(cntPassX==1&&maxX-minX+1>2))*(maxY-minY+1);
        ll ansY=(ll(maxY-minY+1)-(cntPassY==1&&maxY-minY+1>2))*(maxX-minX+1);

        cout<<min(ansX,ansY)<<endl;
    }

    return 0;
}