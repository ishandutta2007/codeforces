const process = require('process');
 
let inp = "";
process.stdin.on('data', chunk => inp += chunk);
process.stdin.on('end', () => {
    inp = inp.split('\n');
    let ic = 0;
    let ntest = +inp[ic++];
    for (let testcase = 0; testcase < ntest; ++testcase) {
        let n = +inp[ic++];
        console.log(Math.floor((n + 1) / 2));
    }

});