const process = require('process');
 
let inp = "";

function min(ba, bb) {
    if (ba < bb) return ba;
    return bb;
}

process.stdin.on('data', chunk => inp += chunk);
process.stdin.on('end', () => {
    inp = inp.split('\n');
    let ic = 0;
    let ntest = +inp[ic++];
    while (ntest--) {
        let [n, r] = inp[ic++].split(' ').map(BigInt);

        let t = min(n - 1n, r);
        let ans = t * (t + 1n) / 2n;
        if (r >= n) {
            ++ans;
        }
        console.log(ans.toString());

    }
});