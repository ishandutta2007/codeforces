#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin.ignore();
    int mx=0, my=0;
    for(int i=0; i<n; i++){
        string temp;
        getline(cin,temp);
        if(temp[0] == '+'){
            string x,y;
            int c=0;
            for(int j=2; j<temp.size(); j++){
                if(temp[j]==' ' && c==0) c=1;
                else if(temp[j]==' ' && c==1) break;
                else if(c==0) x.push_back(temp[j]);
                else y.push_back(temp[j]);
            }
            int x1=stoi(x),y1=stoi(y),dx=0,dy=0,fx=0,fy=0;
            if(x1>mx) dx=x1-mx;
            if(y1>my) dy=y1-my;
            if(x1>my) fx=x1-my;
            if(y1>mx) fy=y1-mx;
            if(dy+dx>fx+fy){
                my+=fx;
                mx+=fy;
            }else{
                mx+=dx;
                my+=dy;
            }
        }else{
            string x,y;
            int c=0;
            for(int j=2; j<temp.size(); j++){
                if(temp[j]==' ' && c==0) c=1;
                else if(temp[j]==' ' && c==1) break;
                else if(c==0) x.push_back(temp[j]);
                else y.push_back(temp[j]);
            }
            int x1=stoi(x),y1=stoi(y);
            if((x1 >= mx && y1 >= my) || (x1 >= my && y1 >= mx)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}