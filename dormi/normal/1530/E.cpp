#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<int> count(26,0);
        for(auto x:s){
            count[x-'a']++;
        }
        bool done=false;
        int charcnt=0;
        for(int i=0;i<26;i++){
            if(count[i])charcnt++;
            if(count[i]==1){
                printf("%c",'a'+i);
                for(int j=0;j<26;j++){
                    if(j!=i){
                        for(int k=0;k<count[j];k++)printf("%c",'a'+j);
                    }
                }
                printf("\n");
                done=true;
                break;
            }
        }
        if(done)continue;
        if(charcnt==1){
            printf("%s\n",s.c_str());
        }
        else if(charcnt==2){
            vector<char> letters;
            vector<int> appear;
            for(int i=0;i<26;i++){
                if(count[i]){
                    letters.push_back('a'+i);
                    appear.push_back(count[i]);
                }
            }
            if(appear[1]>=appear[0]-2){
                printf("%c",letters[0]);
                for(int k=1;k<appear[0];k++){
                    printf("%c",letters[0]);
                    if(appear[1]) {
                        printf("%c", letters[1]);
                        appear[1]--;
                    }
                }
                while(appear[1]){
                    printf("%c", letters[1]);
                    appear[1]--;
                }
            }
            else{
                printf("%c",letters[0]);
                for(int k=0;k<appear[1];k++)printf("%c",letters[1]);
                for(int k=1;k<appear[0];k++)printf("%c",letters[0]);
            }
            printf("\n");
        }
        else{
            for(int i=0;i<26;i++){
                if(count[i]){
                    vector<char> avalible;
                    for(int j=i+1;j<26;j++){
                        for(int k=0;k<count[j];k++)avalible.push_back('a'+j);
                    }
                    reverse(avalible.begin(),avalible.end());
                    if(sz(avalible)>=count[i]-2){
                        printf("%c",'a'+i);
                        for(int k=1;k<count[i];k++){
                            printf("%c",'a'+i);
                            if(sz(avalible)) {
                                printf("%c", avalible.back());
                                avalible.pop_back();
                            }
                        }
                        while(sz(avalible)){
                            printf("%c", avalible.back());
                            avalible.pop_back();
                        }
                    }
                    else{
                        printf("%c",'a'+i);
                        char used=avalible.back();
                        printf("%c", avalible.back());
                        avalible.pop_back();
                        for(int k=1;k<count[i];k++) {
                            printf("%c", 'a' + i);
                        }
                        count[used-'a']--;
                        for(int j=(used-'a')+1;j<26;j++){
                            if(count[j]){
                                printf("%c",'a'+j);
                                count[j]--;
                                break;
                            }
                        }
                        for(int j=i+1;j<26;j++){
                            for(int k=0;k<count[j];k++)printf("%c",'a'+j);
                        }
                    }
                    break;
                }
            }
            printf("\n");
        }
    }
    return 0;
}