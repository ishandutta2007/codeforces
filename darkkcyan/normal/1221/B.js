const process = require('process');
 
let inp = "";
process.stdin.on('data', chunk => inp += chunk);
process.stdin.on('end', () => {
    const n = +inp;
    let u = "";
    let v = "";
    for (let i = 0; i < n; ++i) {
        u += 'W';
        v += 'B';
        [u, v] = [v, u];
    }
    for (let i = 0; i < n; ++i) 
        console.log(i % 2 === 1 ? u : v);
});