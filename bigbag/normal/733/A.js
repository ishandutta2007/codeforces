input = readline();

vowels = ['A','E','I','O','U','Y'];

dist = 1;
longest = 1;
for(var i = 0, len = input.length; i < len; i++) {
    if(vowels.includes(input[i])) {
        longest = Math.max(dist,longest);
        dist = 1;
    } else {
        dist++
    }
}

print(Math.max(longest,dist));