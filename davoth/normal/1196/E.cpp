#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    string s;
    for(int i=0; i<t; i++) {
        int b, w, st = 0, c = 0;
        cin >> b >> w;
        if (b > w) {
            if (b - 1 > w * 3) {
                s += "NO\n";
                c = 1;
            }
            st = 1;
        } else if (w > b) {
            if (w - 1 > b * 3) {
                s += "NO\n";
                c = 1;
            }
        }
        if (c != 1){
            vector< pair<int, int> > ans;
            for (int x = 5; w>0 && b>0; x++) {
                for(int y=5+st; w>0 && b>0; y++){
                    if((x+y)%2==0){
                        w--;
                    }else{
                        b--;
                    }
                    ans.push_back(pair <int, int>(x+1,y+1));
                    if((b==0 && w>0) || (w==0 && b>0)){
                        ans.push_back(pair <int, int>(x+1,y+2));
                        b--;
                        w--;
                    }
                }
            }
            int an=ans.size();
            for(int j=0; w>0; j++){
                if((ans[j].first+ans[j].second)%2==1){
                    ans.push_back(pair<int,int>(ans[j].first-1,ans[j].second));
                    w--;
                    if(w) {
                        ans.push_back(pair<int, int>(ans[j].first + 1, ans[j].second));
                        w--;
                    }
                }
            }
            for(int j=0; b>0; j++){
                if((ans[j].first+ans[j].second)%2==0){
                    ans.push_back(pair<int,int>(ans[j].first-1,ans[j].second));
                    b--;
                    if(b){
                        ans.push_back(pair<int,int>(ans[j].first+1,ans[j].second));
                        b--;
                    }
                }
            }
            s+="YES\n";
            for(int j=0; j<ans.size(); j++){
                s+=to_string(ans[j].first);
                s+=' ';
                s+=to_string(ans[j].second);
                s+='\n';
            }
        }
    }
    cout << s;
    return 0;
}