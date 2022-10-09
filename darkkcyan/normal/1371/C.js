const process = require('process');
 
let inp = "";
process.stdin.on('data', chunk => inp += chunk);
process.stdin.on('end', () => {
    inp = inp.split('\n');
    let ic = 0;
    for (let ntest = +inp[ic++]; ntest--; ) {
        let [a, b, n, m] = inp[ic++].split(' ').map(BigInt);
        if (n + m > a + b) {
            console.log("No");
            continue;
        }
        if (m > (a < b ? a : b)) {
            console.log("No");
            continue;
        }
        console.log("Yes");
    }
});