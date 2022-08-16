#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
//#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
                #define MAX 600005

                // Ideally, we should not use global variables and large
                // constant-sized arrays, we have done it here for simplicity.
                pii tree[MAX],cmpp={0,0};  // To store segment tree
                pii lazy[MAX];  
                /*  si -> index of current node in segment tree
                    ss and se -> Starting and ending indexes of elements for
                                 which current nodes stores sum.
                    us and ue -> starting and ending indexes of update query
                    diff -> which we need to add in the range us to ue */
                void updateRangeUtil(int si, int ss, int se, int us,
                                     int ue, pii diff)
                {
                    // If lazy value is non-zero for current node of segment
                    // tree, then there are some pending updates. So we need
                    // to make sure that the pending updates are done before
                    // making new updates. Because this value may be used by
                    // parent after recursive calls (See last line of this
                    // function)
                    if (lazy[si] != cmpp)
                    {
                        // Make pending updates using value stored in lazy
                        // nodes
                        tree[si] = max(tree[si],lazy[si]);

                        // checking if it is not leaf node because if
                        // it is leaf node then we cannot go further
                        if (ss != se)
                        {
                            // We can postpone updating children we don't
                            // need their new values now.
                            // Since we are not yet updating children of si,
                            // we need to set lazy flags for the children
                            lazy[si*2+1] = max(lazy[si],lazy[si*2+1]);
                            lazy[si*2+2] = max(lazy[si],lazy[si*2+2]);
                        }

                        // Set the lazy value for current node as 0 as it
                        // has been updated
                        lazy[si] = {0,0};
                    }

                    // out of range
                    if (ss>se || ss>ue || se<us)
                        return ;

                    // Current segment is fully in range
                    if (ss>=us && se<=ue)
                    {
                        // Add the difference to current node
                        tree[si] = max(diff,tree[si]);

                        // same logic for checking leaf node or not
                        if (ss != se)
                        {
                            // This is where we store values in lazy nodes,
                            // rather than updating the segment tree itelf
                            // Since we don't need these updated values now
                            // we postpone updates by storing values in lazy[]
                            lazy[si*2 + 1]  = max(lazy[si*2 + 1],diff);
                            lazy[si*2 + 2]  = max(lazy[si*2 + 2],diff);
                        }
                        return;
                    }

                    // If not completely in rang, but overlaps, recur for
                    // children,
                    int mid = (ss+se)/2;
                    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
                    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);

                    // And use the result of children calls to update this
                    // node
                    tree[si] = max(tree[si*2+1],tree[si*2+2]);
                }

                // Function to update a range of values in segment
                // tree
                /*  us and eu -> starting and ending indexes of update query
                    ue  -> ending index of update query
                    diff -> which we need to add in the range us to ue */
                void updateRange(int n, int us, int ue, pii diff)
                {
                   updateRangeUtil(0, 0, n-1, us, ue, diff);
                }


                /*  A recursive function to get the sum of values in given
                    range of the array. The following are parameters for
                    this function.
                    si --> Index of current node in the segment tree.
                           Initially 0 is passed as root is always at'
                           index 0
                    ss & se  --> Starting and ending indexes of the
                                 segment represented by current node,
                                 i.e., tree[si]
                    qs & qe  --> Starting and ending indexes of query
                                 range */
                pii getSumUtil(int ss, int se, int qs, int qe, int si)
                {
                    // If lazy flag is set for current node of segment tree,
                    // then there are some pending updates. So we need to
                    // make sure that the pending updates are done before
                    // processing the sub sum query
                    if (lazy[si] != cmpp)
                    {
                        // Make pending updates to this node. Note that this
                        // node represents sum of elements in arr[ss..se] and
                        // all these elements must be increased by lazy[si]
                        tree[si] = max(tree[si],lazy[si]);
                        // checking if it is not leaf node because if
                        // it is leaf node then we cannot go further
                        if (ss != se)
                        {
                            // Since we are not yet updating children os si,
                            // we need to set lazy values for the children
                            lazy[si*2+1] = max(lazy[si],lazy[si*2+1]);
                            lazy[si*2+2] = max(lazy[si],lazy[si*2+2]);
                        }

                        // unset the lazy value for current node as it has
                        // been updated
                        lazy[si] = {0,0};
                    }

                    // Out of range
                    if (ss>se || ss>qe || se<qs)
                        return cmpp;

                    // At this point we are sure that pending lazy updates
                    // are done for current node. So we can return value
                    // (same as it was for query in our previous post)

                    // If this segment lies in range
                    if (ss>=qs && se<=qe)
                        return tree[si];

                    // If a part of this segment overlaps with the given
                    // range
                    int mid = (ss + se)/2;
                    return max(getSumUtil(ss, mid, qs, qe, 2*si+1),
                           getSumUtil(mid+1, se, qs, qe, 2*si+2));
                }

                // Return sum of elements in range from index qs (quey
                // start) to qe (query end).  It mainly uses getSumUtil()
                pii getSum(int n, int qs, int qe)
                {
                    // Check for erroneous input values
                    if (qs < 0 || qe > n-1 || qs > qe)
                    {
                        printf("Invalid Input");
                        return cmpp;
                    }

                    return getSumUtil(0, n-1, qs, qe, 0);
                }
pii vals[100003];
long long int dp[100002][201];
int n,m,k;
long long int calc(int tim,int rem){
    if(tim>=n)return 0;
    long long int& ans=dp[tim][rem];
    if(ans!=-1)return ans;
    if(vals[tim].fr==0){
        return calc(tim+1,rem);
    }
    ans=vals[tim].fr+calc(vals[tim].sc,rem);
    if(rem>0)ans=min(ans,calc(tim+1,rem-1));
    return ans;
}
void solve(){
    cin>>n>>m>>k;//cout<<n;
    for(int i=0;i<k;i++){
        int s,t,d,w;
        cin>>s>>t>>d>>w;
        updateRange(n,s-1,t-1,{w,d});
    }
    for(int i=0;i<n;i++){
        vals[i]=getSum(n,i,i);
    }
    /*
    memset(dp,-1,sizeof(dp));
    cout<<calc(0,m);
    */
    for(int pos=n-1;pos>=0;pos--){
        for(int i=0;i<=m;i++){
            long long int& ans=dp[pos][i];
            if(vals[pos].fr==0){
                ans=dp[pos+1][i];
                continue;
            }
            ans=vals[pos].fr+dp[vals[pos].sc][i];
            if(i>0)ans=min(ans,dp[pos+1][i-1]);
        }
    }
    cout<<dp[0][m];
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}