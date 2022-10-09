const process = require('process');
 
let inp = "";
process.stdin.on('data', chunk => inp += chunk);
process.stdin.on('end', () => {
    inp = inp.split('\n');
    let ic = 0;
    for (let ntest = +inp[ic++]; ntest--; ) {
        let [n, r] = inp[ic++].trim().split(' ').map(x => +x);
        let a = [];
        for (let i = 0; i < n; ++i) {
            let row = [];
            for (let f = 0;f < n; ++f) row.push(0);
            a.push(row);
        }

        let d = Math.floor(r / n);
        for (let r = 0; r < n; ++r) {
            for (let i = 0; i < d; ++i) {
                let c = (r + i) % n;
                a[r][c] = 1;
            }
        }
        let rem = r % n;
        for (let i = 0; i < rem; ++i) {
            let c = (i + d) % n;
            a[i][c] = 1;
        }

        console.log(rem ? 2 : 0);
        console.log(a.map(row => row.join('')).join('\n'));
    }
});