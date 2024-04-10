#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=100000;
int nextsong[MAXN],prevsong[MAXN],nextdelete[MAXN];
int arr[MAXN];
int do_gcd(int a, int b){
    if (b==0)return a;
    return do_gcd(b,a%b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc;
    cin>>tc;
    for (int ct=0;ct!=tc;++ct){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        for(int i=1;i<n;++i){
            nextsong[i-1]=i;
            prevsong[i]=i-1;
        }
        nextsong[n-1]=0;
        prevsong[0]=n-1;
        int scratch;
        int* delhandle=&scratch;
        for(int i=1;i<n;++i){
            if(do_gcd(arr[i-1],arr[i])==1){
                *delhandle=i;
                delhandle=&nextdelete[i];
            }
        }
        if(do_gcd(arr[n-1],arr[0])==1){
            *delhandle=0;
            delhandle=&nextdelete[0];
        }
        if(delhandle==&scratch){
            cout<<"0\n";
            continue;
        }
        *delhandle=scratch;
        vector<int> ans;
        while (true){
            ans.push_back(scratch);
            if (nextsong[scratch]==scratch)break;
            nextsong[prevsong[scratch]]=nextsong[scratch];
            prevsong[nextsong[scratch]]=prevsong[scratch];
            if (delhandle==&nextdelete[scratch]){
                if(do_gcd(arr[prevsong[scratch]],arr[nextsong[scratch]])!=1)break;
                scratch=nextsong[scratch];
                delhandle=&nextdelete[scratch];
                *delhandle=scratch;
                continue;
            }
            int nexttarget=nextdelete[scratch];
            if (nexttarget==nextsong[scratch]){
                if(delhandle==&nextdelete[nexttarget]){
                    if(do_gcd(arr[prevsong[scratch]],arr[nexttarget])!=1)break;
                    scratch=nexttarget;
                    delhandle=&nextdelete[scratch];
                    *delhandle=scratch;
                    continue;
                }
                nexttarget=nextdelete[nexttarget];
            }
            if(do_gcd(arr[prevsong[scratch]],arr[nextsong[scratch]])!=1){
                scratch=nexttarget;
                *delhandle=scratch;
            }
            else {
                scratch=nextsong[scratch];
                *delhandle=scratch;
                delhandle=&nextdelete[scratch];
                scratch=nexttarget;
                *delhandle=scratch;
            }
        }
        cout<<ans.size();
        for (int x : ans){
            cout<<' '<<x+1;
        }
        cout<<'\n';
    }
}