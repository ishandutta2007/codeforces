#include<bits/stdc++.h>
using namespace std;

const char vowel[5]={'a','e','i','o','u'};

int isvowel(const char &c){
    for(int i=0;i<5;i++){
        if(c==vowel[i])return (i+1);
    }
    return 0;
}

struct compressed{
    int cnt;
    char last;
};

int n;
string s[114514];
compressed a[114514];
vector<pair<int,int> > c[6];
vector<int> o[2];
vector<pair<int,int> > fst,snd;
vector<int> possible;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        int cnt=0;
        char last;
        for(int j=0;j<s[i].size();j++){
            if(isvowel(s[i][j]))cnt++,last=s[i][j];
        }
        a[i].cnt=cnt;
        a[i].last=last;
        c[isvowel(last)].push_back(make_pair(cnt,i));
        possible.push_back(cnt);
    }
    for(int i=1;i<=5;i++){
        sort(c[i].begin(),c[i].end());
        c[i].push_back(make_pair(-1,-1));
        for(int j=0;j+1<c[i].size();){
            if(c[i][j].first==c[i][j+1].first){
                snd.push_back(make_pair(c[i][j].second,c[i][j+1].second));
                j+=2;
            }else{
                c[0].push_back(c[i][j]);
                j++;
            }
        }
    }
    sort(c[0].begin(),c[0].end());
    c[0].push_back(make_pair(-1,-1));
    for(int i=0;i+1<c[0].size();i++){
        if(c[0][i].first==c[0][i+1].first){
            fst.push_back(make_pair(c[0][i].second,c[0][i+1].second));
            i++;
        }
    }
    if(fst.size()>=snd.size()){
        cout<<snd.size()<<endl;
        for(int i=0;i<snd.size();i++){
            cout<<s[fst[i].first]<<' '<<s[snd[i].first]<<endl;
            cout<<s[fst[i].second]<<' '<<s[snd[i].second]<<endl;
        }
    }else{
        cout<<(fst.size()+(snd.size()-fst.size())/2)<<endl;
        for(int i=0;i<fst.size();i++){
            cout<<s[fst[i].first]<<' '<<s[snd[i].first]<<endl;
            cout<<s[fst[i].second]<<' '<<s[snd[i].second]<<endl;
        }
        for(int i=fst.size();i+1<snd.size();i+=2){
            cout<<s[snd[i].first]<<' '<<s[snd[i+1].first]<<endl;
            cout<<s[snd[i].second]<<' '<<s[snd[i+1].second]<<endl;
        }
    }

    return 0;
}