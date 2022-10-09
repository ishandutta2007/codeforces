const {stdin, exit} = require('process');
let inp = "";
stdin.on('data', chunk => inp += chunk).on('end', () => {
    let [a, b] = inp.split('\n').map(s => s.trim());
    if (a === b) console.log(-1);
    else console.log(Math.max(a.length, b.length));
})