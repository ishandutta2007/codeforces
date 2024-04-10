#include <iostream>
#include <queue>
#include <unordered_map>
#include <iomanip>

using namespace std;
typedef int var;

unordered_map<var, double> Prob;

struct Node {
    var r, p, s;
    #define P 100003
    Node(var r, var p, var s) {
        this->r = r;
        this->p = p;
        this->s = s;
    }
    var hashMe() {
        return r*P*P + p*P + s;
    }
};
queue<Node> Q;

int main() {
    var r, p, s;
    cin>>r>>s>>p;

    Q.push(Node(r, p, s));
    Prob[Q.front().hashMe()] = 1.0;

    double cr = 0, cp = 0, cs = 0;

    while(!Q.empty()) {
        Node top = Q.front();
        Q.pop();

        // cerr << top.r << " " << top.p << " " << top.s << " Prob: " << Prob[top.hashMe()] << endl;

        var V[4] = {top.r, top.p, top.s, top.r};

        if(top.r == 0 && top.p == 0) {
            cs += Prob[top.hashMe()];
            continue;
        }
        if(top.p == 0 && top.s == 0) {
            cr += Prob[top.hashMe()];
            continue;
        }
        if(top.s == 0 && top.r == 0) {
            cp += Prob[top.hashMe()];
            continue;
        }

        for(var i=0; i<3; i++) {
            if(V[i] && V[i+1]) {
                double inm = 1.0 * (V[i] * V[i+1]) / (top.r * top.p + top.p * top.s + top.s * top.r);

                V[i] --;
                Node next(V[0], V[1], V[2]);
                if(Prob.find(next.hashMe()) == Prob.end()) {
                    Prob[next.hashMe()] = 0;
                    Q.push(next);
                }
                Prob[next.hashMe()] += Prob[top.hashMe()] * inm;
                V[i] ++;

            }
        }
    }


    cout<<fixed<<setprecision(10)<<cr<<" "<<cs<<" "<<cp;

    return 0;
}