#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,cnt=0,ml,mr;
    cin >> n >> k;
    deque<int> dq;
    int a[1000001];
    fill(a,a+1000001,0);
    int m=-1;
    int r=0,l=1;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        if(a[t]>0){
            dq.push_front(t);
            a[t]++;
            r=i+1;
        }
        else if(cnt<k){
            cnt++;
            a[t]++;
            dq.push_front(t);
            r=i+1;
        }else{
            while(true){
                int b=dq.back();
                a[b]--;
                dq.pop_back();
                l++;
                if(a[b]==0) break;
            }
            dq.push_front(t);
            a[t]++;
            r=i+1;
        }
        if(r-l+1>m){
            m=r-l+1;
            mr=r;
            ml=l;
        }
    }
    cout << ml << ' ' << mr;
	return 0;
}